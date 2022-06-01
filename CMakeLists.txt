cmake_minimum_required(VERSION 3.21)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers
                main.cpp
        vector/vector.hpp
                iterator/classes/iterator.hpp
                iterator/classes/iterator_traits.hpp
                iterator/classes/iterator_tr.hpp
        vector/elements_access.cpp
        vector/constructors.cpp)
