cmake_minimum_required(VERSION 3.10)
project(luajit-swig-test)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

find_package(PkgConfig REQUIRED)
pkg_check_modules(LUAJIT REQUIRED luajit)

include_directories(${LUAJIT_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/src)
link_directories(${LUAJIT_LIBRARY_DIRS})

set_source_files_properties(swig/example.i PROPERTIES CPLUSPLUS ON)
swig_add_library(example 
                 LANGUAGE lua 
                 TYPE SHARED
                 SOURCES swig/example.i src/example.cpp)
target_link_libraries(example ${LUAJIT_LIBRARIES})

add_executable(luajit-cpp-swig-interop src/main.cpp)
target_link_libraries(luajit-cpp-swig-interop ${LUAJIT_LIBRARIES} example)

file(COPY ${CMAKE_SOURCE_DIR}/scripts/ DESTINATION ${CMAKE_BINARY_DIR}/scripts/)
