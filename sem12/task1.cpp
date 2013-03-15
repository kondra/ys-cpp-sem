#include <iostream>
#include <vector>
#include <cstddef>

template<class T>
class Allocator {
  private:
    static const size_t internal_size = 10000;
    static T* buffer;
    static bool is_filled[internal_size];
  public:
    typedef T value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T* reference;
    typedef const T* const_reference;

    pointer address(reference r) const {
      return &r;
    }

    Allocator() throw() {
    }

    template<class U> Allocator(const Allocator<U>& other) throw() {
    }

    ~Allocator() {
    }

    pointer allocate(size_type n) {
      std::cout << "allocate n = " << n << "\n";
      int position = -1;
      size_t block_size = 0;
      for (size_t i = 0; i < internal_size; ++i) {
        if (is_filled[i] == false) {
          ++block_size;
        } else {
          block_size = 0;
        }
        if (block_size >= n) {
          position = i - block_size + 1;
          break;
        }
      }
      for (size_t i = position; i < position + block_size; ++i) {
        is_filled[i] = true;
      }
      return buffer + position;
    }

    void deallocate(pointer p, size_type n) {
      std::cout << "deallocate n = " << n << "\n";
      size_t offset = p - buffer;
      for (size_t i = 0; i < n; ++i) {
        is_filled[offset + i] = false;
      }
    }

    void construct(pointer p, const T& val) {
      std::cout << "construct, val = " << val << "\n";
      new (p) T(val);
    }

    void destroy(pointer p) {
      std::cout << "destroy\n";
      p->~T();
    }

    size_type max_size() const throw() {
      return internal_size;
    }

    template<class U> struct rebind {
      typedef Allocator<U> other;
    };
};

template<class T>
T* Allocator<T>::buffer = (T*)::operator new(sizeof(T) * Allocator<T>::internal_size);   //reinterpret_cast<T*>(new char[sizeof(T) * Allocator<T>::internal_size]);
template<class T>
bool Allocator<T>::is_filled[Allocator<T>::internal_size];

int main() {
  std::vector<int, Allocator<int> > v;

  v.push_back(42);
  v.push_back(239);
  v.push_back(179);
  v.push_back(13);

  return 0;
}
