#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <cstring>

int main() {
  std::string filename;
  std::cin >> filename;

  std::ifstream in(filename.c_str());
  std::map<std::string, std::vector<int> > dictionary;
  std::string line, word;

  size_t line_number = 1;

  while (in) {
    std::getline(in, line);
    for (size_t i = 0; i < line.length(); ++i) {
      if (isalpha(line[i])) {
        word.push_back(tolower(line[i]));
      } else if (word.length()) {
        dictionary[word].push_back(line_number);
        word.clear();
      }
    }
    if (word.length()) {
      dictionary[word].push_back(line_number);
      word.clear();
    }
    ++line_number;
  }

  std::map<std::string, std::vector<int> >::iterator iter = dictionary.begin();
  while (iter != dictionary.end()) {
    std::cout << iter->first << ' ';
    int prev = -1;
    for (size_t i = 0; i < iter->second.size(); ++i) {
      if (prev != iter->second[i]) {
        std::cout << (prev = iter->second[i]) << ' ';
      }
    }
    std::cout << '\n';
    ++iter;
  }

  in.close();
  return 0;
}
