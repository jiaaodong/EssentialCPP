cmake_minimum_required(VERSION 3.0.0)
project(EssentialCpp VERSION 0.1.0)

include(CTest)
enable_testing()
# The directories for header files
include_directories(include)
# The directories for libraries (different from header files, libraries are complied implementation) 
# link_directories() 
# The link libraries in static mode
# target_link_libraries()
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_executable(learn_vscode_cpp src/main.cpp)
add_executable(ex1_4 src/ex1_4.cpp)
add_executable(page7_guessing_number src/page7.cpp)
add_executable(fibo_elem src/fibo_elem.cpp)
add_executable(bubble_sort src/bubble_sort.cpp)
add_executable(iterator_insertor src/iterator_inserter.cpp)
add_executable(read_from_stdio src/read_from_stdio.cpp)
add_executable(try_const_vector_ptr src/try_const_vector_ptr.cpp)
add_executable(ex2_2 src/ex2_2.cpp)
add_executable(iostream_iterator1 src/iostream_iterator1.cpp)
add_executable(ex3_1 src/ex3_1.cpp)
add_executable(ex4_1 src/ex4_1.cpp src/Stack.cpp)
add_executable(test_trian  src/Triangular.cpp src/Triangular_iterator.cpp src/test_trian.cpp )
add_executable(test_matrix src/Matrix.cpp src/test_Matrix.cpp)
add_executable(test_num_sequence src/test_num_sequence.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
