#include <iostream>
#include <cassert>

template<typename T>
class CowPtr {
private:
  T *ptr;
  size_t *counter;

  void clear() {
    --(*counter);
    if (*counter == 0) {
      delete counter;
      delete ptr;
    }
  }
public:
  CowPtr(T *ptr): ptr(ptr) {
    counter = new size_t;
    *counter = 1;
  }
  CowPtr& operator = (const CowPtr& other) {
    clear();
    counter = other.counter;
    ++(*counter);
    ptr = other.ptr;
  }
  CowPtr(const CowPtr& other) {
    counter = other.counter;
    ++(*counter);
    ptr = other.ptr;
  }
  const T* Const() const {
    return ptr;
  }
  T* Mutable() {
    if (*counter > 1) {
      --(*counter);
      T *old_ptr = ptr;
      ptr = new T(*old_ptr);
      counter = new size_t;
      *counter = 1;
    }
    return ptr;
  }
  ~CowPtr() {
    clear();
  }
};

struct Test {
  static int counter;
  int a;
  Test(const Test& other) {
    std::cout << "copy\n";
    ++counter;
  }
  Test(int a): a(a) {
    std::cout << "ololo in constructor\n";
    ++counter;
  }
  ~Test() {
    std::cout << "ololo in destructor\n";
    --counter;
  }
};

int Test::counter = 0;

int main() {
  CowPtr<Test> cp1(new Test(1));

  assert(Test::counter == 1);

  CowPtr<Test> cp2(new Test(10));

  std::cout << cp2.Const()->a << '\n';

  assert(Test::counter == 2);

  cp2 = cp1;

  assert(Test::counter == 1);
  
  std::cout << cp2.Const()->a << '\n';

  assert(Test::counter == 1);

  cp2.Mutable()->a = 100;

  assert(Test::counter == 2);

  cp2.Mutable()->a += 10;

  assert(Test::counter == 2);

  std::cout << cp2.Const()->a << '\n';

  assert(Test::counter == 2);

  return 0;
}
