std::bind2nd(std::less<int>, t);
std::bind1st(std::greater<int>, t);

bool g(int a, int b) {
  return a < b;
}

std::ptr_fun(g); //обернуть функцию в функтор

struct C {
  void h(int x) {
    //...
  }
};

void (C::*q) (int);
q = C::h;
C x;
(x.*q)(123);

mem_fun_ref(&C::g); //c C
mem_fun(&C::g); // c С*

template<typename Arg1, typename Arg2, typename Res>
void f1(Res(Arg1, Arg2)) {

}

f1(f);
