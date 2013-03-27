#include <iostream>
#include <string>
#include <cstring>

class TooMuchArguments {
};

class NotEnoughArguments {
};

void helper(const char * str, size_t pos) {
//  if (pos != str.size()) {
  if (pos != strlen(str)) {
    throw NotEnoughArguments();
  }
}

template<typename T, typename ... Args>
void helper(const char * str, size_t pos, T t, Args ... args) {
  std::cout << t;
  while (str[pos] != ' ' && str[pos] != '\\') {
    ++pos;
  }
  size_t len = strlen(str);
  for (size_t i = pos; i < len; ++i) {
    if (i < len - 1 && str[i] == '%' && str[i + 1] == '%') {
      i += 2;
      continue;
    }
    if (str[i] == '%') {
      for (size_t j = pos; j < i; ++j) {
        std::cout << str[j];
      }
//      std::cout << std::string(str.begin() + pos, str.begin() + i);
      helper(str, i, args...);
      return;
    }
  }
  if (sizeof...(args) > 0) {
    throw TooMuchArguments();
  }
  for (size_t j = pos; j < len; ++j) {
    std::cout << str[j];
  }
//  std::cout << std::string(str.begin() + pos, str.end());
}

template<typename ... Args>
void my_printf(const char * str, Args ... args) {
  size_t len = strlen(str);
  for (size_t i = 0; i < len; ++i) {
    if (i < len - 1 && str[i] == '%' && str[i + 1] == '%') {
      i += 2;
      continue;
    }
    if (str[i] == '%') {
      //std::cout << std::string(str.begin(), str.begin() + i);
      for (size_t j = 0; j < i; ++j) {
        std::cout << str[j];
      }
      helper(str, i, args...);
      return;
    }
  }
}

int main() {
  char s[] = "world";
  double d = 0.4;
  my_printf("%%hello %d hello %lf hello %s ababab\n", 123, d, s);
  return 0;
}
