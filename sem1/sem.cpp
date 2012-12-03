#include <iostream>

template<typename T>
class Array {
  private:
    const size_t size_;
    T *data_;

  public:
    Array(size_t size) : size_(size), data_(new T[size_]) {
    }

    //if there are no exceptions this is good:
    Array(const Array& other) : size_(other.size_) {
      data_ = new T[size_];
      try {
        for (size_t i = 0; i != size_; ++i) {
          data_[i] = other.data_[i];
          //if exception -> memory leak
        }
      } catch (...) {
        delete [] data_;
        throw;
      }
    }

    ~Array() {
      delete [] data_;
    }

    T& operator [] (size_t i) {
      // Array<T> * const this
      return data_[i];
    }

    const T& operator [] (size_t i) const {
      // Array<T> const * const this
      return data_[i];
    }

    typedef T value_type;
    typedef T * iterator
    typedef T const * const_iterator

    iterator begin() {
      return data_;
    }

    iterator end() {
      return data_ + size_;
    }

    const_iterator begin() const {
      return data_;
    }

    const_iterator end() const {
      return data_ + size_;
    }

    void swap(Array& rhs) {
      std::swap(size, rhs.size);
      std::swap(data, rhs.data);
    }

    Array& operator = (const Array& rhs) {
      Array temp(rhs);
      swap(temp);
      /* Naive version
      if (&rhs == this) {
        return *this;
      }
      size_ = rhs.size_;
      delete [] data_;
      ...
      */
    }

    /*
    Array(const Array& other) : size_(other.size_), data_(other.data_) {
    }
    */

    /* Compiler version of =
    Array& operator = (const Array& rhs) {
      size_ = rhs.size_;
      data_ = rhs.data_;
    }
    */
}

int main() {
  return 0;
}
