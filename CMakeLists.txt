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
        iterator/iterator_category.hpp
        iterator/iterator_base.hpp
        iterator/value_type.hpp
        iterator/distance_type.hpp
        iterator/iterator_swap.hpp
        iterator/iterator_advance.hpp
        iterator/iterator_distance.hpp
        vector/elements_access.hpp
        vector/member_functions.hpp
        vector/iterators.hpp
        vector/capacity.hpp
        vector/modifiers.hpp
        vector/protected.hpp
        algorithm/copy.hpp
        algorithm/fill.hpp)
