//const_expr

constexpr int g(int a) {
  return 5 * a == 5 ? 0 : 1;
}

const int M = 5;

int array[g(5)];

//variadic templates
#include <iostream>

class A {};
class B {};

template<typename ... Args>
class C: public Args ... {
public:
  void f() const {
    std::cout << sizeof...(Args) << '\n';
  }
};

void f() {
  std::cout << "void\n";
}

template<typename T, typename ... Args>
void f(T t, Args ... args) {
  std::cout << t << '\n';
  f(args...);
}

int main() {
  C<A> c;
  C<A, B> d;
  c.f();
  d.f();
  std::cout << "begin\n";
  f(1,2,3,4);
  return 0;
}
