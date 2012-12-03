template<int A, int B>
struct Divides {
  static const bool Result = A % B == 0;
};

template<int A, int B>
struct Iterate {
  static const bool Result = !Divides<A, B>::Result && Iterate<A, B - 1>::Result;
};

template<int A>
struct Iterate<A, 2> {
  static const bool Result = !Divides<A, 2>::Result;
};

template<int A>
struct IsPrime {
  static const bool Result = Iterate<A, A - 1>::Result;
};

template<>
struct IsPrime<2> {
  static const bool Result = true;
};

template<bool B>
struct Dummy;

template<>
struct Dummy<false> {
  static const bool dummy = false;
};

template<int N>
struct Next {
  Next() {
    Next<N - 1>();
    Dummy<IsPrime<N>::Result >();
  }
};

template<>
struct Next<2> {
  Next() {
    Dummy<true>();
  }
};


int main() {
  Next<101>();
  return 0;
}
