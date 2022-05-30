#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

template <class Iterator> class iterator_traits;

template <class T> class iterator_traits<T*>;

template <class T> class iterator_traits<const T*>;

#endif
