class A {
public:
  A Clone() const {
    return *this;
  }
  A foo() const {
    return *this;
  }
};

class B {
};

template<typename T>
class IsCloneable {
public:
  IsCloneable() {
    T (T::*f)() const = &T::Clone;
  }
};

template<typename T>
class MyClass: private IsCloneable<T> {
};

template<bool s>
struct static_assert {};

template<>
struct static_assert<false> {
private:
  static_assert();
};

class Base {};
class Derived: public Base {};
class NotDerived {};

template<typename D, typename B>
class IsDerivedFrom {
private:
  char foo(B*) {
    return '\0';
  }
  double foo(...) {
    return 0.0;
  }
public:
  IsDerivedFrom() {
    static_assert<foo((D*)0) == 1>();
  }
};

template<typename D, typename B>
class MyClass2: private IsDerivedFrom<D, B> {
};

int main() {
  /*
  MyClass<A> m1;
  MyClass<B> m2;
  */
//  MyClass2<NotDerived, Base> m1;
  return 0;
}
