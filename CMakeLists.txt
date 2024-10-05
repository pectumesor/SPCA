cmake_minimum_required(VERSION 3.29)
project(SPCA C)

set(CMAKE_C_STANDARD 11)

add_executable(SPCA main.c BST/binary_search_tree.c BST/binary_search_tree.h
sorted_linked_list/sorted_linked_list.c sorted_linked_list/sorted_linked_list.h
        Bits/bits_ops.c
        Bits/bit_ops.h
        function_pointer/function_pointer.c
        function_pointer/function_pointer.h)
