cmake_minimum_required(VERSION 3.16)
project(quadratic_equation)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        solver
        src/main.cpp
        src/solver.cpp
        src/solver.h)

add_executable(
        tests
        test/testlib.h
        test/testlib.cpp
        test/main.cpp
        test/solve_linear_tests.cpp
        src/solver.cpp
        src/solver.h
        test/solve_quadratic_tests.cpp)