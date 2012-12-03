#include <iostream>

template<typename T> class MyList;
template<typename T> class MyListIterator;
template<typename T> class Item;

template<typename T>
class MyListIterator: public std::iterator<T, std::forward_iterator_tag> {
  private:
    Item<T> *item_;
  public:
    MyListIterator(Item<T> *item) : item_(item) {
    }
    T& operator * () {
      return item_->value_;
    }
    void operator ++ () {
      item_ = item_->next_;
    }
    void operator ++ (int) {
      MyListIterator tmp(*this);
      item_ = item_->next_;
      return tmp;
    }
    bool operator == (const MyListIterator other) const {
      return item_ == other.item_;
    }
    bool operator != (const MyListIterator other) const {
      return item_ != other.item_;
    }
};

template<typename T>
class Item {
  private:
    T value_;
    Item *next_;
  public:
    Item(const T& value, Item *next) : value_(value), next_(next) {
    }

    template<typename U> friend class MyList;
    template<typename U> friend class MyListIterator;
};

template<typename T>
class MyList {
  private:
    Item<T> *first_;
    size_t length_;

    MyList(const MyList&);
    MyList& operator = (const MyList&);
  public:
    MyList() : first_(0), length_(0){
    }

    bool empty() const {
      return length_ == 0;
    }

    size_t length() const {
      return length_;
    }

    void push_back(const T& element) {
      Item<T> *previous = 0;
      Item<T> *current = first_;
      while (current != 0) {
        previous = current;
        current = current->next_;
      }
      if (previous != 0) {
        previous->next_ = new Item<T>(element, 0);
      } else {
        first_ = new Item<T>(element, 0);
      }
      length_++;
    }

    ~MyList() {
      Item<T> *previous = 0;
      Item<T> *current = first_;
      while (current != 0) {
        previous = current;
        current = current->next_;
        delete previous;
      }
    }

    typedef MyListIterator<T> iterator;
    typedef T value_type;

    iterator begin() {
      return MyListIterator<T>(first_);
    }
    iterator end() {
      return MyListIterator<T>(0);
    }

    template<typename U> friend class MyListIterator;
};

int main() {
  int array[10] = {2, 3, 5, 6, 1, 3, 8, 2, 4, 1};
  MyList<int> l;
  for (size_t i = 0; i < 10; ++i) {
    l.push_back(array[i]);
  }
  std::cout << l.length() << '\n';
  for (MyList<int>::iterator it = l.begin(); it != l.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
  return 0;
}
