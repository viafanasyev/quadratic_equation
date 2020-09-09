# Quadratic equation solver

## Project description

This program is developed as a part of ISP RAS course.

### Structure

* src/ : Main project
    * main.cpp : Entry point for the program. Reads from user and solves quadratic equation.
    * solver.h, solver.cpp : Description and implementation of quadratic and linear equation solver functions.

* test/ : Tests and testing library
    * testlib.h, testlib.cpp : Library for testing with assertions and helper macros.
    * solve_linear_test.cpp : Linear equations solver tests.
    * solver_quadratic_tests.cpp : Quadratic equation solver tests.
    * main.cpp : Entry point for tests. Just runs all tests.

* doc/ : doxygen documentation

* doxyfile.txt : doxygen config file

### Run

#### Solver

To run main program execute next commands in terminal:
```
cmake .
make
./solver
```

#### Tests

To run tests execute next commands in terminal:
```
cmake .
make
./tests
```

To run tests from file execute next commands in terminal:
```
cmake .
make
./tests file_with_tests.txt
```

File with tests should have next format: `a b c roots_number [root_1] [root_2]`  
Example:
```
1 0 -4 2 -2 2
0 1 2 1 -2
0 1 0 1 0
0 0 1 0
```

### Documentation

Doxygen is used to create documentation. You can watch it by opening `doc/html/index.html` in browser.  

### OS

Program is developed under Ubuntu 20.04.1 LTS.