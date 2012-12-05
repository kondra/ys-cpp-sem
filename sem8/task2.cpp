#include <string>
#include <cstring>
#include <iostream>

class rev_char_traits: public std::char_traits<char> {
public:
  static int compare(const char *s1, const char *s2, size_t n) {
    int len1 = 0, len2 = 0;
    while (*s1++ != 0)
      ++len1;
    while (*s2++ != 0)
      ++len2;
    char * end1 = const_cast<char*>(s1 + len1);
    char * end2 = const_cast<char*>(s2 + len2);

    n = std::min(len1, len2);

    while (n-->0) {
      if (*s1 != *s2) {
        return *s1 - *s2;
      }
      --s1;
      --s2;
    }

    return 0;
  }
};

typedef std::basic_string<char, rev_char_traits> rev_string;

int main() {
  rev_string s1 = "aabc";
  rev_string s2 = "abc";
  rev_string s3 = "abc";

  std::cout << (s1 < s2) << '\n';
  std::cout << (s1 > s2) << '\n';
  std::cout << (s2 == s3) << '\n';
  return 0;
}
