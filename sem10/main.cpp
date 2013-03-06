#include <iostream>

//T* operator->();
//T& operator*();

Holder<T> ptr(new T());

//template parameter of template
template<typename T, class <typename> CreatorPolicy>
class DeepPtr: public CreatorPolicy<T>;

int main() {
  return 0;
}
