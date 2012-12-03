#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <iterator>

template<typename Iter>
struct iterator_traits1 {
  typedef typename Iter::iterator_category iterator_category;
};

template<typename T>
struct iterator_traits1<T*> {
  typedef typename std::random_access_iterator_tag iterator_category;
};

template<typename T>
struct iterator_traits1<T*const> {
  typedef typename std::random_access_iterator_tag iterator_category;
};

//iterators
template<typename T>
class MyIterator: public std::iterator<T, std::random_access_iterator_tag>  {
//  typedef std::random_access_iterator_tag  iterator_category;
//  typedef ... value_type;
//  typedef ptrdiff_t difference_type;
};

template<typename Iter, typename Category>
size_t distance_impl(Iter a, Iter b, Category) {
  size_t counter = 0;
  while (a != b) {
    ++counter;
    ++a;
  }
  return counter;
}

/*
template<typename Iter, typename Category>
size_t distance_impl(Iter a, Iter b, Category) {
  return b - a;
}
*/

template<typename Iter>
size_t distance1(Iter a, Iter b) {
  return distance_impl(a, b, typename std::iterator_traits<Iter>::iterator_category());
}

int main() {
  std::vector<int> v;
  std::list<int> l;
  distance1(v.begin(), v.end());
  distance1(l.begin(), l.end());
}

/*
//

class MyZeroDivideException;
class Complex;

class MyZeroDivideException {
  private:
    Complex numerator;
  public:
    MyZeroDivideException(const Complex& c) : numerator(c) {
    }
    const Complex& GetNumerator() const {
      return numerator;
    }
    const char * what() {
      return "division by zero";
    }
};

class Complex {
  private:
    double x, y;
  public:
    Complex operator / (const Complex& z) const {
      if (z == 0) {
        throw MyZeroDivideException(*this);
      }
    }

    operator double() const {
      return sqrt(x*x + y*y);
    }
};

//приведение типов
Complex z;
double a = z;

void f() {
  std::vector<int> v;
  throw 123;

  throw "Hello world";
}

void g() {
  std::list<int> l;
  f();
}

class A {
  private:
    int a;
  public:
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef T* pointer;
    typedef T& reference;
    typedef T const * const_pointer;
    typedef const T& const_reference;
}

int  main() {
  Complex a, b;
  try{
    a / b;
  } catch (const MyZeroDivideException& ex) {
    ex.GetNumerator();
    std::cerr << ex.what();
  } catch (...) {

  }

  try {
    f();
  } catch (int a) {

  } catch (const std::exception&) {

  } catch (const char *s) {

  } catch (double) {
    throw;
  }
  return 0;
}
  */
