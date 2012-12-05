#include <iostream>

class A {
public:
  typedef int value_type;
};

class B {
protected:
  typedef int value_type;
};

class C {
};

template<typename T>
class IsDefined {
  class D: public T {
  public:
    typedef typename T::value_type dt;
  };
public:
  typedef typename D::dt it;
  IsDefined() {
  }
};

template<typename T>
class MyClass: private IsDefined<T> {
};

int main() {
  MyClass<A> m1;
  MyClass<B> m2;
  MyClass<C> m3;
  return 0;
}
