cmake_minimum_required(VERSION 3.21)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)

add_executable(ft_containers
        main.cpp
        vector/vector.hpp
        vector/vector_base.hpp
        vector/vector_elements_access.hpp
        vector/vector_member_functions.hpp
        vector/vector_template_functions.hpp
        vector/vector_iterators.hpp
        vector/vector_capacity.hpp
        vector/vector_modifiers.hpp
        vector/vector_protected.hpp
        iterator/iterator.hpp
        iterator/iterator_traits.hpp
        iterator/iterator_tags.hpp
        iterator/reverse_iterator.hpp
        iterator/random_access_iterator.hpp
        iterator/iterator_category.hpp
        iterator/iterator_base.hpp
        iterator/iterator_value_type.hpp
        iterator/iterator_distance_type.hpp
        iterator/iterator_swap.hpp
        iterator/iterator_advance.hpp
        iterator/iterator_distance.hpp
        algorithm/algorithm.hpp
        algorithm/copy.hpp
        algorithm/fill.hpp
        stack/stack.hpp
        stack/stack_capacity.hpp
        stack/stack_element_access.hpp
        stack/stack_member_functions.hpp
        stack/stack_modifiers.hpp
        stack/stack_non_member_functions.hpp
        set/set.hpp
        set/set_traits.hpp
        set/set_constructors.hpp
        map/map_base.hpp
        tree/tree.hpp
        tree/tree_lookup.hpp
        tree/tree_base.hpp
        tree/tree_nod.hpp
        tree/tree_ptr.hpp
        tree/tree_traits.hpp
        tree/tree_value.hpp
        tree/tree_constructors.hpp
        tree/tree_iterator.hpp
        tree/const_tree_iterator.hpp
        tree/tree_protected.hpp
        tree/tree_iterators.hpp
        tree/tree_modifiers.hpp
        tree/tree_capacity.hpp
        tree/tree_observers.hpp
        utility/enable_if.hpp utility/pair.hpp utility/is_integral.hpp utility/utility.hpp utility/equal.hpp utility/lexicographical_compare.hpp utility/make_pair.hpp)
