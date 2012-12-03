template<bool B> 
struct static_assert;

template<>
struct static_assert<true> {
};

int main() {
  static_assert<2*2==5>();
  return 0;
}
