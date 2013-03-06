#include <iostream>
#include <cstdlib>

class C {
private:
  int b;
  char x;
public:
/*  static void * operator new(size_t sz, double d) {
    std::cout << "new (" << sz << ", " << d << ")\n";
    void * p =  malloc(sz);
    if (p == 0) {
      throw std::bad_alloc();
    }
    return p;
  }

  static void operator delete(void * ptr, double d = 0.0) {
    std::cout << "delete (" << d << ")\n";
    free(ptr);
  }

  static void operator delete(void * ptr, size_t sz) {
    std::cout << "delete (" << sz << ")\n";
    free(ptr);
  }
*/

  C() try : b(42), x('@') {
//    throw 42;
  } catch (...) {
  }

  virtual ~C() {
  }
};

class D: public C {
  char x;
  int z;
};

/*
void * operator new(size_t sz) {
  std::cout << "new (" << sz << ")\n";
  void * p =  malloc(sz);
  if (p == 0) {
    throw std::bad_alloc();
  }
  return p;
}

//void operator delete[](void * ptr) {
//  std::cout << "delete\n";
//  free(ptr);
//}

void operator delete(void * ptr, size_t sz) {
  std::cout << "delete (" << sz << ")\n";
  free(ptr);
}
*/

int main() try {
  unsigned char buf[1000];

  for (size_t i = 0; i != sizeof(C); ++i) {
    std::cout << ((int)buf[i]) << " ";
  }
  std::cout << "\n";

  C *a = new (buf) C;

  for (size_t i = 0; i != sizeof(C); ++i) {
    std::cout << ((int)buf[i]) << " ";
  }
  std::cout << "\n";

  //после размещающего оператора new
  a->~C();

  for (size_t i = 0; i != sizeof(C); ++i) {
    std::cout << ((int)buf[i]) << " ";
  }
  std::cout << "\n";

//  delete a;

  return 0;
} catch (...) {
  std::cout << "1111\n";
}
