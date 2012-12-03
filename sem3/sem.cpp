template<int A, int N>
struct Power {
  static const int Result = A * Power<A, N - 1>::Result;
};

template<int A>
struct Power<A, 0> {
  static const int Result = 1;
};

template<int M>
class Dummy;

int main() {
  Dummy<Power<2, 16>::Result>();
  return 0;
}
