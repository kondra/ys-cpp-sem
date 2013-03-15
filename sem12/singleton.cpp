#include <iostream>

class Singleton {
private:
  Singleton() {
    std::cout << "Singleton()\n";
  }
  Singleton(const Singleton&);
  Singleton& operator = (const Singleton&);

//  static Singleton * instance = NULL;

public:
  static Singleton& GetInstance() {
    static Singleton instance;
    return instance;
  }
  ~Singleton() {
  }
};

int main() {
  Singleton& s = Singleton::GetInstance();
  return 0;
}
