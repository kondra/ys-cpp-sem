#include <iostream>

template<typename T>
class Holder {
private:
  T* ptr;

  Holder& operator = (const Holder&);
  Holder(const Holder&);
public:
  Holder(T* ptr) : ptr(ptr) {
  }
  ~Holder() {
    delete ptr;
  }
  T& operator*() const {
    return *ptr;
  }
  T* operator->() const {
    return ptr;
  }
};

struct Test {
  int a;
  int b;
};

template<typename T>
class ArrayHolder {
private:
  T* ptr;

  ArrayHolder& operator = (const ArrayHolder&);
  ArrayHolder(const ArrayHolder&);
public:
  ArrayHolder(T* ptr) : ptr(ptr) {
  }
  ~ArrayHolder() {
    delete [] ptr;
  }
  T& operator [] (size_t i) const {
    return ptr[i];
  }
  T& operator*() const {
    return *ptr;
  }
  T* operator->() const {
    return ptr;
  }
};

int main() {
  Holder<int> h1(new int);
  Holder<double> h0(new double);
  Holder<int> h2(new int);
  Holder<int> h3(new int);

  ArrayHolder<int> ah0(new int[200]);

  *h1 = 0;
  std::cout << *h1 << std::endl;
  
  Holder<Test> th(new Test);
  th->a = 1;
  th->b = 0;
  std::cout << th->a << ' ' << th->b << '\n';

  ah0[20] = 128;
  std::cout << ah0[20] << '\n';

  return 0;
}
