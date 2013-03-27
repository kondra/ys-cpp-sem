#include <iostream>
#include <utility>

//move constructor

using namespace std;

class Class {
  public:
    Class() {
    }

    void fun(Class const &other) {
      cout << "fun class const &\n";
      gun(other);
    }
    void fun(Class &other) {
      cout << "fun class &\n";
      gun(other);
    }
    void fun(Class &&tmp) {
      cout << "fun class &&\n";
      gun(std::move(tmp));
    }
    void gun(Class const &other) {
      cout << "gun class const &\n";
    }
    void gun(Class &other) {
      cout << "gun class &\n";
    }
    void gun(Class &&tmp) {
      cout << "gun class &&\n";
    }
};

int main() {
  Class c1;
  c1.fun(c1);
  c1.fun(Class());
  Class const c0;
  c1.fun(c0);

  return 0;
}
