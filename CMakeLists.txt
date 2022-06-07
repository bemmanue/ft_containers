cmake_minimum_required(VERSION 3.21)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers
                main.cpp
                vector/vector.hpp
                iterator/iterator.hpp
                iterator/iterator_traits.hpp
                iterator/iterator_tags.hpp
                iterator/reverse_iterator.hpp
                iterator/random_access_iterator.hpp
        vector/elements_access.hpp
        vector/constructors.hpp
        vector/iterators.hpp
        vector/capasity.hpp
        vector/modifiers.hpp)
