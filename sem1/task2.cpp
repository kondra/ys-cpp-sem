#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T> class column_iterator;
template<typename T> class row_iterator;

template<typename T>
class Matrix {
  private:
    size_t size_;
    std::vector<std::vector<T> > data_;

  public:
    explicit Matrix(size_t size) : size_(size) {
      if (size == 0) {
        throw std::logic_error("empty matrix");
      }
      data_.resize(size_);
      for (size_t i = 0; i < size_; ++i) {
        data_[i].resize(size_, 0);
      }
    }

    Matrix& operator += (const Matrix& other) {
      if (size_ != other.size_) {
        throw std::logic_error("different sizes of matrices");
      }
      for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
          data_[i][j] += other.data_[i][j];
        }
      }
      return *this;
    }

    Matrix& operator -= (const Matrix& other) {
      if (size_ != other.size_) {
        throw std::logic_error("different sizes of matrices");
      }
      for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
          data_[i][j] -= other.data_[i][j];
        }
      }
      return *this;
    }

    Matrix& operator *= (const Matrix& other) {
      if (size_ != other.size_) {
        throw std::logic_error("different sizes of matrices");
      }
      Matrix temp(size_);
      for (size_t i = 0; i < size_; ++i) {
        for (size_t j = 0; j < size_; ++j) {
          for (size_t k = 0; k < size_; ++k) {
            temp.data_[i][j] = data_[i][k] * data_[k][j];
          }
        }
      }
      *this = temp;
      return *this;
    }

    Matrix& operator + (const Matrix& other) const {
      Matrix result(*this);
      return result += other;
    }

    Matrix& operator - (const Matrix& other) const {
      Matrix result(*this);
      return result -= other;
    }

    Matrix& operator * (const Matrix& other) const {
      Matrix result(*this);
      return result *= other;
    }

    bool operator == (const Matrix& other) const {
      if (size_ != other.size_) {
        return false;
      }
      return data_ == other.data_;
    }

    bool operator != (const Matrix& other) const {
      return !(*this == other);
    }

    Matrix& operator = (const Matrix& other) {
      size_ = other.size_;
      data_ = other.data_;
    }

    T& operator () (size_t i, size_t j) {
      return data_[i][j];
    }

    row_iterator<T> row_begin() {
      return row_iterator<T>(this, 0, 0);
    }

    row_iterator<T> row_end() {
      return row_iterator<T>(this, size_, size_);
    }

    column_iterator<T> column_begin() {
      return column_iterator<T>(this, 0, 0);
    }

    column_iterator<T> column_end() {
      return column_iterator<T>(this, size_, size_);
    }

    template<typename U>
    friend std::ostream& operator << (std::ostream& os, const Matrix<U>& matrix);

    template<typename U>
    friend class column_iterator;
    template<typename U>
    friend class row_iterator;
};

template<typename T>
std::ostream& operator << (std::ostream& os, const Matrix<T>& matrix) {
  for (size_t i = 0; i < matrix.size_; ++i) {
    for (size_t j = 0; j < matrix.size_; ++j) {
      os << matrix.data_[i][j] << ' ';
    }
    os << '\n';
  }
  return os;
}

template<typename T>
class row_iterator {
  private:
    Matrix<T> *matrix_;
    size_t i_, j_;
  public:
    row_iterator(Matrix<T> * matrix, size_t i, size_t j) : matrix_(matrix), i_(i), j_(j) {
    }

    bool operator == (const row_iterator& other) const {
      return (i_ == other.i_) && (j_ == other.j_);
    }

    bool operator != (const row_iterator& other) const {
      return (i_ != other.i_) || (j_ != other.j_);
    }

    row_iterator& operator++ () {
      ++i_;
      if (i_ == matrix_->size_) {
        ++j_;
        if (i_ == matrix_->size_ && j_ == matrix_->size_)
          return *this;
        i_ = 0;
      }
      return *this;
    }

    row_iterator& operator++ (int) {
      row_iterator temp(*this);
      ++i_;
      if (i_ == matrix_->size_) {
        ++j_;
        if (i_ == matrix_->size_ && j_ == matrix_->size_)
          return *this;
        i_ = 0;
      }
      return temp;
    }

    T& operator * () {
      return matrix_->data_[i_][j_];
    }

    const T& operator * () const {
      return matrix_->data_[i_][j_];
    }
};

template<typename T>
class column_iterator {
  private:
    Matrix<T> *matrix_;
    size_t i_, j_;
  public:
    column_iterator(Matrix<T>* matrix, size_t i, size_t j) : matrix_(matrix), i_(i), j_(j) {
    }

    bool operator == (const column_iterator& other) const {
      return (i_ == other.i_) && (j_ == other.j_);
    }

    bool operator != (const column_iterator& other) const {
      return (i_ != other.i_) || (j_ != other.j_);
    }

    column_iterator& operator++ () {
      ++j_;
      if (j_ == matrix_->size_) {
        ++i_;
        if (i_ == matrix_->size_ && j_ == matrix_->size_)
          return *this;
        j_ = 0;
      }
      return *this;
    }

    column_iterator& operator++ (int) {
      column_iterator temp(*this);
      ++j_;
      if (j_ == matrix_->size_) {
        ++i_;
        if (i_ == matrix_->size_ && j_ == matrix_->size_)
          return *this;
        j_ = 0;
      }
      return temp;
    }

    T& operator * () {
      return matrix_->data_[i_][j_];
    }

    const T& operator * () const {
      return matrix_->data_[i_][j_];
    }
};

int main() {
  Matrix<int> m1(3);

  m1(0, 0) = 1;
  m1(2, 0) = 2;
  m1(0, 2) = 3;

  std::cout << m1 << std::endl;

  for (column_iterator<int> it = m1.column_begin(); it != m1.column_end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
  for (row_iterator<int> it = m1.row_begin(); it != m1.row_end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  return 0;
}
