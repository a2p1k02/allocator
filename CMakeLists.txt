cmake_minimum_required(VERSION 3.5)

project(allocator LANGUAGES C)

add_executable(allocator src/main.c src/allocator/allocator.h src/allocator/allocator.c)
#add_executable(allocator src/main.c)
