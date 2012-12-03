#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <cstring>

int main() {
  std::string filename;
  std::cin >> filename;

  std::ifstream in(filename.c_str());

  std::map<std::string, std::vector<size_t> > dictionary;
  std::map<std::string, size_t> ref;
  std::map<std::string, std::vector<size_t> >::const_iterator iter = dictionary.begin();
  std::map<std::string, size_t>::const_iterator found;

  std::vector<std::string> synonyms;
  std::string line, word, key;
  std::vector<size_t> index;

  while (in) {
    std::getline(in, line);

    if (line.length() == 0) {
      break;
    }

    size_t count = 0;
    for (size_t i = 0; i < line.length(); ++i) {
      if (line[i] == ' ') {
        if (count == 0) {
          key = word;
        } else {
          found = ref.find(word);
          if (found == ref.end()) {
            index.push_back(synonyms.size());
            ref[word] = synonyms.size();
            synonyms.push_back(word);
          } else {
            index.push_back(found->second);
          }
        }
        word.clear();
        ++count;
        continue;
      }
      word.push_back(line[i]);
    }

    if (word.size()) {
      found = ref.find(word);
      if (found == ref.end()) {
        index.push_back(synonyms.size());
        ref[word] = synonyms.size();
        synonyms.push_back(word);
      } else {
        index.push_back(found->second);
      }
    }
    dictionary[key] = index;
    index.clear();
    word.clear();
  }

  std::cout << "Synonyms: \n";
  for (size_t i = 0; i < synonyms.size(); ++i) {
    std::cout << synonyms[i] << '\n';
  }
  std::cout << '\n';
  std::cout << "Dict: \n";
  iter = dictionary.begin();
  while (iter != dictionary.end()) {
    std::cout << iter->first << '\n';
    ++iter;
  }
  std::cout << '\n';

  std::cin >> word;

  bool equal = false;
  iter = dictionary.begin();
  while (iter != dictionary.end()) {
    equal = true;
    if (iter->first.length() < word.length()) {
      ++iter;
      continue;
    }
    for (size_t i = 0; i < word.length(); ++i) {
      if (word[i] != iter->first[i]) {
        equal = false;
        break;
      }
    }
    if (equal) {
      break;
    }
    ++iter;
  }

  if (!equal) {
    std::cout << "No such word in dictionary\n";
  } else {
    std::cout << iter->first << "\n";
    for (size_t i = 0; i < iter->second.size(); ++i) {
      std::cout << synonyms[iter->second[i]] << '\n';
    }
  }

  in.close();
  return 0;
}
