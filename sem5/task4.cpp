
template<typename Iter>
Iter adjacent_find(Iter first, Iter last);

template<typename Iter, typename Predicate>
size_t count_if(Iter first, Iter last, Predicate p);

template<typename Iter1, typename Iter2>
Iter2 copy_backward(Iter1 first, Iter1 last, Iter2 result);

template<typename Iter, typename Function>
void transform(Iter first, Iter last, Function f);

template<typename Iter, typename Iter2, typename T>
void replace_copy_if(Iter first, Iter last, Iter2 result, const T& old_val, const T& new_val);

template<typename Iter, typename Iter2>
Iter2 rotate_copy(Iter first, Iter last, Iter2 result);

template<typename Iter, typename Generator>
void generate_n(Iter first, Iter last, Generator g);

template<typename Iter, typename Iter2>
Iter2 unique_copy(Iter first, Iter last, Iter2 result);

template<typename Iter>
void random_shuffle(Iter first, Iter last);

template<typename Iter, typename T>
Iter stable_partition(Iter first, Iter last, const T& pivot);

template<typename Iter>
Iter nth_element(Iter first, Iter last, size_t n);

template<typename Iter, typename T>
Iter equal_range(Iter first, Iter last, const T& elem);

template<typename Iter, typename T>
Iter includes(Iter first, Iter last, const T& elem);

template<typename Iter, typename Iter2>
Iter2 inner_product(Iter first1, Iter last1, Iter first2, Iter2 result);

template<typename Iter>
Iter partial_sum(Iter first, Iter last);
