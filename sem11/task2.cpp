#include <iostream>

const size_t buffer_size = 1024;

template <typename T>
class stack {
private:
  size_t last_free;
  char buffer[buffer_size];

  stack(const stack& other);
  stack& operator = (const stack& other);
public:
  stack(): last_free(0) {
  }
  T top() const {
    return *(buffer + last_free - sizeof(T));
  }
  void push_back(const T& elem) {
    if (last_free + sizeof(T) > buffer_size) {
      throw std::bad_alloc();
    }
    new (buffer + last_free) T(elem);
    last_free += sizeof(T);
  }
  void pop_back() {
    if (last_free == 0) {
      throw;
    }
    char *ptr = buffer + last_free - sizeof(T);
    ((T*)ptr)->~T();
    last_free -= sizeof(T);
  }
};

int main() {
  stack<int> st;
  st.push_back(10);
  st.push_back(12);
  st.push_back(13);
  st.push_back(14);
  st.push_back(15);
  st.push_back(17);
  std::cout << st.top() << "\n";
  st.pop_back();
  std::cout << st.top() << "\n";
  return 0;
}
