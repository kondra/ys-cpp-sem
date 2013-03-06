#include <iostream>

class X {};

class Y {};

//отложенная инициализация
class Z {
  X * x;
  Y * y;
public:
  Z() {
    x = new X();
    try {
      y = new Y();
    } catch(...) {
      delete x;
      throw;
    }
  }
  ~Z() {
    delete x;
    delete y;
  }
  Z(const Z& z) {
    x = new X(*z.x);
    try {
      y = new Y(*z.y);
    } catch(...) {
      delete x;
      throw;
    }
  }
  void swap(Z& z) {
    std::swap(x, z.x);
    std::swap(y, z.y);
  }
  Z& operator = (const Z& z) {
    if (this == &z) {
      return *this;
    }
    Z tmp(z);
    swap(tmp);
    return *this;

    /*
     * очень плохо. удалили x, а хотим revert при исключении
    delete x;
    delete y;
    x = new X(*z.x);
    try {
    x = new X(*z.x);
    } catch(...) {
      delete x;
    }
    return *this;
    */
  }
  /*
  Z(): x(0) {}
  void Init(const std::string& f) {
    x = new X(f);
  }
  */

};

//smart pointer

template<typename T>
class Holder {
  T *data;
public:
  operator T * () const {
    return data;
  }
  Holder() {
    data = new T;
  }
  ~Holder() {
    delete data;
  }
};

class Z1{
  Holder<X> = x;
  Holder<Y> = y;
public:
  Z1() {
  }
  ~Z1() {
  }
};

int main() {
  return 0;
}
