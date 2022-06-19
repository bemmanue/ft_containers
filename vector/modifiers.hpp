#pragma once

#include "vector.hpp"

namespace ft
{

    template <class Iter1, class Iter2>
    Iter1 copy_forward(Iter1 x, Iter2 first, Iter2 last)
    {
        while (first != last) {
            *x++ = *first++;
        }
        return (x);
    }

    template <class Iter1, class Iter2>
    Iter1 copy_backward(Iter1 x, Iter2 first, Iter2 last)
    {
        while (first != last) {
            *--x = *--last;
        }
        return (x);
    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::clear() {
        if (_first) {
            destroy(_first, _last);
            _last = _first;
        }
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::insert(iterator pos, const T &value) {
        size_type off = size() == 0 ? 0 : pos - begin();
        insert(pos, 1, value);
        return begin() + off;
    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::insert(iterator pos, size_type count, const T &value) {
        size_t max_size = this->max_size();
        size_t capacity = this->capacity();
        size_t size = this->size();

        if (count == 0) {
            ;
        } else if (count > max_size - size) {
            throw std::length_error("vector");
        } else if ((size + count) > capacity) {
            size_t new_capacity = (max_size - (capacity / 2)) < capacity ? 0 : (capacity * 2);
            if (new_capacity < size + count)
                new_capacity = size + count;
            pointer new_first = _allocator.allocate(new_capacity, nullptr);
            pointer new_last;
            try {
                new_last = copy(new_first, begin(), pos);
                new_last = fill(new_last, count, value);
                copy(new_last, pos, end());
            } catch (...) {
                destroy(new_first, new_last);
                _allocator.deallocate(new_first, new_capacity);
                throw;
            }
            if (_first) {
                clean();
            }
            _first = new_first;
            _last = new_first + size + count;
            _end = new_first + new_capacity;
        } else if ((size_type)(end() - pos) < count) {
            copy(pos.base(), pos, end());
            try {
                fill(_last, count - (end() - pos), value);
            } catch (...) {
                destroy(pos.base() + count, _last + count);
                throw;
            }
            _last += count;
            fill(pos, pos + count, value);
        } else {
            iterator end = end();
            _last = copy(_last, end - count, _end);
            copy_backward(pos, end - count, end);
            fill(pos.base(), pos + count, value);
        }
    }

    template <typename T, class Alloc>
    template<class InputIt>
    void vector<T, Alloc>::insert(iterator pos, InputIt first, InputIt last) {
        insert(pos, first, last, iterator_category(last));
    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator pos) {

    }

    template <typename T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::erase(iterator first, iterator last) {

    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::push_back(const T &value) {

    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::pop_back() {
        size_t n = size();
        if (n == 0) {
            ;
        } else {
            _allocator.destroy(_last);
            _last--;
        }
    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::resize(size_type count) {

    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::resize(size_type count, T value) {

    }

    template <typename T, class Alloc>
    void vector<T, Alloc>::swap(vector &other) {

    }

}
