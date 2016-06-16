cmake_minimum_required(VERSION 2.6)
project(list)

include_directories(src)

add_executable(main src/list.c src/main.c)
add_executable(test_list src/list.c test/list_test.c test/unity.c)

enable_testing()
add_test(test_list test_list)

