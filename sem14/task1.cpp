#include <iostream>

constexpr bool helper(int number, int divider) {
  return divider < number ? (number % divider == 0 ? false : helper(number, divider + 1)) : true;
}

constexpr bool is_prime(int number) {
  return helper(number, 2);
}

int main() {
  static_assert(is_prime(29), "29 is not prime");
  static_assert(is_prime(15), "15 is not prime");
  static_assert(is_prime(27), "27 is not prime");
  static_assert(is_prime(49), "49 is not prime");
  static_assert(is_prime(30), "30 is not prime");

  return 0;
}
