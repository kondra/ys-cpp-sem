#include <string>
#include <cstring>
#include <iostream>

//wchar_t;
//std::wstring;

//typedef std::basic_string<char, std::char_traits<char>> string;
//typedef std::basic_string<wchar_t> wstring;


class MyCharTraits: public std::char_traits<char> {
public:
  static bool eq(char a, char b) {
    return tolower(a) == tolower(b);
  }
  static bool lt(char a, char b) {
    return tolower(a) < tolower(b);
  }
  static int compare(const char *s1, const char *s2, size_t n) {
    while (n-->0) {
      if (!eq(*s1, *s2)) {
        return lt(*s1, *s2) ? -1 : 1;
      }
      ++s1;
      ++s2;
    }
    return 0;
  }
};

typedef std::basic_string<char, MyCharTraits> MyString;

int main() {
  MyString s1 = "abc", s2 = "AbC";
  std::cout << (s1 == s2) << "\n";
  return 0;
}
