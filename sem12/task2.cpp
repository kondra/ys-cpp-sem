#include <iostream>

template<typename T>
class Singleton {
private:
  Singleton(const Singleton&);
  Singleton& operator = (const Singleton&);

public:
  Singleton() {
    std::cout << "Singleton()\n";
  }
  static T& GetInstance() {
    static T instance;
    return instance;
  }
};

class DerivedSingleton: public Singleton<DerivedSingleton> {
private:
  friend class Singleton<DerivedSingleton>;
  DerivedSingleton(const DerivedSingleton&);
  DerivedSingleton& operator = (const DerivedSingleton&);
  DerivedSingleton() {
    std::cout << "DerivedSingleton()\n";
  }
};

int main() {
  DerivedSingleton& d = DerivedSingleton::GetInstance();
//  DerivedSingleton d2;
  return 0;
}
