#include <iostream>

template<typename T>
class C {
public:
  static const int N = 128;
  static bool A[N];

  static size_t Memory;
  static void * operator new(size_t sz) {
    void *p = ::operator new(sz);
    Memory += sz;
    return p;
  }
  static void operator delete(void * ptr, size_t sz) {
    ::operator delete(ptr);
    Memory -= sz;
  }
  virtual ~C() {
  }
};

class D: public C<D> {
  char y;
  int b;
};

template<typename T>
bool C<T>::A[C<T>::N] = {false};

template<typename T>
size_t C<T>::Memory = 0;

int main() {
  D * c = new D;
  std::cout << D::Memory << std::endl;
  delete c;
  std::cout << D::Memory << std::endl;
  return 0;
}
