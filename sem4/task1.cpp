#include <iostream>
#include <vector>
#include <string>

std::string Join(const std::vector<std::string>& strs, const std::string& delim) {
  std::string result;

  for (size_t i = 0; i < strs.size(); ++i) {
    result += strs[i];
    if (i + 1 == strs.size()) {
      continue;
    }
    result += delim;
  }

  return result;
}

void Split(const std::string& str, char delim, std::vector<std::string>* res) {
  std::string buffer;
  size_t j = 0;
  for (size_t i = 0; i < str.length(); ++i) {
    if (str[i] == delim) {
      res->push_back(buffer);
      buffer.clear();
      continue;
    }
    buffer.push_back(str[i]);
  }
  if (buffer.size()) {
    res->push_back(buffer);
  }
}

void Split(const std::string& str, const std::string& delim, std::vector<std::string>* res) {
  std::string buffer;
  size_t i, j;
  for (i = 0; i < str.length(); ++i) {
    bool equal = true;
    for (j = 0; j < delim.length(); ++j) {
      if (str[i + j] != delim[j]) {
        equal = false;
        break;
      }
    }
    if (equal) {
      if (j == 0) {
        buffer.push_back(str[i]);
      }
      res->push_back(buffer);
      buffer.clear();
      i += delim.length() - 1;
      continue;
    }
    buffer.push_back(str[i]);
  }
  if (buffer.size()) {
    res->push_back(buffer);
  }
}

template<typename Inp, typename Out>
Out Split(const std::string& str, Inp firstDelim, Inp lastDelim, Out result) {
  std::string buffer;
  std::string delim;
  size_t i, j;
  for (i = 0; i < str.length(); ++i) {
    Inp iter = firstDelim;
    bool splitted = false;
    while (iter != lastDelim) {
      delim = *iter;
      bool equal = true;
      for (j = 0; j < delim.length(); ++j) {
        if (str[i + j] != delim[j]) {
          equal = false;
          break;
        }
      }
      if (equal) {
        if (j == 0) {
          buffer.push_back(str[i]);
        }
        *result = buffer;
        ++result;
        buffer.clear();
        i += delim.length() - 1;
        splitted = true;
        break;
      }
      ++iter;
    }
    if (splitted) {
      continue;
    }
    buffer.push_back(str[i]);
  }
  if (buffer.size()) {
    *result = buffer;
    ++result;
  }
  return result;
}

int main() {
  std::vector<std::string> strs;
  strs.push_back("foo");
  strs.push_back("bar");
  strs.push_back("baz");
  std::string ss;
  ss = Join(strs, "-");
  std::cout << "joined:" << ss << '\n';
  std::vector<std::string> res;
  ss = "-" + ss + "-";
  std::string delim;
  Split(ss, "ba", &res);
  std::cout << ss << ":\n";
  for (size_t i = 0; i < res.size(); ++i) {
    std::cout << res[i] << '\n';
  }
  std::vector<std::string> delims;
  delims.push_back("oo");
  delims.push_back("ba");
  std::string s = "badfoodfdfbabalskdjflksjdfjlsoojjjoo";
  std::vector<std::string> ans(100);
  std::vector<std::string>::iterator iter, last;
  last = Split(s, delims.begin(), delims.end(), ans.begin());
  std::cout << s << ":\n";
  iter = ans.begin();
  while (iter != last) {
    std::cout << *iter << '\n';
    ++iter;
  }
  return 0;
}
