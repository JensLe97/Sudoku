cmake_minimum_required(VERSION 3.14.0)
project(Sudoku VERSION 0.1.0)

add_executable(Sudoku main.cpp sudoku.cpp sudoku.h util.cpp util.h)
target_compile_features(Sudoku PUBLIC cxx_std_20)

include(CTest)
add_subdirectory(test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
