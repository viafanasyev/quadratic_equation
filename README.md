# Quadratic equation solver

## Project description

This program is developed as a part of ISP RAS course.

### Structure

* src
    * main.cpp : Entry point for the program. Reads from user and solves quadratic equation.
    * solver.h, solver.cpp : Description and implementation of quadratic and linear equation solver functions.

* test
    * testlib.h, testlib.cpp : Library for testing with assertions and helper macros.
    * solve_linear_test.cpp : Linear equations solver tests.
    * solver_quadratic_tests.cpp : Quadratic equation solver tests.
    * main.cpp : Entry point for tests. Just runs all tests.

### Run

To run main program execute next commands in terminal:
```
cmake .
make
./solver
```

To run tests execute next commands in terminal:
```
cmake .
make
./tests
```

### OS

Program is developed under Ubuntu 20.04.1 LTS.