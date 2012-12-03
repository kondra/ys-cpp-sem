#include <iostream>
#include <functional>
#include <iterator>
#include <string>
#include <algorithm>
#include <cmath>

template<typename Arg, typename Res>
struct FunctionImpl {
  virtual Res operator()(Arg x) const = 0;
  virtual ~FunctionImpl() {
  }
};

template<typename Arg, typename Res>
struct FunctionImplPtr: public FunctionImpl<Arg, Res> {
  Res (*func)(Arg);
  FunctionImplPtr(Res(*f)(Arg)) : func(f) {
  }
  Res operator()(Arg x) const {
    return func(x);
  }
};

template<typename F>
struct FunctionImplFunctor: public FunctionImpl<typename F::argument_type, typename F::result_type> {
  F func;
  FunctionImplFunctor(F f) : func(f) {
  }
  typename F::result_type operator()(typename F::argument_type x) const {
    return func(x);
  }
};

template<typename C, typename Arg, typename Res>
struct FunctionImplClass: public FunctionImpl<Arg, Res> {
  Res (C::*func)();
  FunctionImplClass(Res(C::*f)()) : func(f) {
  }
  Res operator()(Arg c) const {
    return (c.*func)();
  }
};

template<typename T>
struct Function {
};

template<typename Arg, typename Res>
struct Function<Res(Arg)> {
  FunctionImpl<Arg, Res> * pImpl;

  Function(Res(*f)(Arg)) {
    pImpl = new FunctionImplPtr<Arg, Res>(f);
  }

  template<typename F>
  Function(F f) {
    pImpl = new FunctionImplFunctor<F>(f);
  }

  template<typename C>
  Function(Res(C::*f)()) {
    pImpl = new FunctionImplClass<C, Arg, Res>(f);
  }

  Res operator()(Arg x) const {
    return (*pImpl)(x);
  }

  ~Function() {
    delete pImpl;
  }
};

int f(double x) {
  return round(x);
}

struct C {
  void g() {
    std::cout << "c\n";
  }
};

int main() {
  Function<int(double)> func1 = f;
  std::cout << func1(3.14) << std::endl;

  Function<void(C&)> func2 = &C::g;
  C c;
  func2(c);

  Function<bool(int)> func3 = std::bind2nd(std::less<int>(), 10);
  std::cout << func3(15) << std::endl;

  return 0;
}
