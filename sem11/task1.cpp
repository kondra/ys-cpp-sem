#include <iostream>

class A {
private:
  static const size_t Size = 18;
  static char buffer[Size];
  static bool is_filled[Size];

  int a;
public:
  static void * operator new(size_t sz) {
    for (size_t i = 0; i < Size; i += sz) {
      if (!is_filled[i]) {
        std::cout << "position in buffer = " << i << "\n";
        is_filled[i] = true;
        return buffer + i;
      }
    }
    return ::operator new(sz);
  }
  static void operator delete(void * ptr, size_t sz) {
    if (ptr >= buffer && ptr < buffer + Size) {
      size_t pos = ((char*)ptr) - buffer;
      for (size_t i = pos; i < pos + sz; ++i) {
        is_filled[i] = false;
      }
      std::cout << "in buffer at position " << pos << ", size = " << sz << "\n";
      return;
    }
    ::operator delete(ptr);
  }
};

char A::buffer[A::Size] = {0};
bool A::is_filled[A::Size] = {false};

int main() {
  A *a1 = new A;
  A *a2 = new A;
  delete a1;
  A *a3 = new A;
  delete a2;
  delete a3;
  A *a4 = new A;

  return 0;
}
