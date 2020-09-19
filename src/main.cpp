/**
 * @file
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include "solver.h"

/**
 * Reads a whole line from a given stream.
 * @param[in,out] stream stream to read from
 * @return line that was read.
 */
char* readLine(FILE* stream = stdin) {
    assert(stream != nullptr);

    size_t size = 0;
    char* line = nullptr;
    const size_t len = getline(&line, &size, stream);
    line[len - 1] = '\0'; // to remove '\n'
    return line;
}

/**
 * Converts the given C-style string to a double.
 * @param[in] string string to convert
 * @param[out] value converted value
 * @return true, if conversion succeeded, false otherwise.
 */
bool toDouble(const char* string, double& value) {
    assert(string != nullptr);

    char* endptr = nullptr;
    value = strtod(string, &endptr);
    return (*endptr == '\0') && (endptr != string);
}

/**
 * Prompts user to write a double and reads it from the standard input stream.
 * If the input was invalid, notifies user about it and reads double again.
 * @param[in] prompt informative message before user input
 * @return inputted double value.
 */
double getDouble(const char* prompt) {
    assert(prompt != nullptr);

    double input = NAN;
    printf("%s", prompt);
    while (!toDouble(readLine(), input)) {
        printf("Invalid input! Try again\n");
        printf("%s", prompt);
    }
    return input;
}

//----------------------------------------------------------------------------------------------------------------------

int main() {
    printf("Welcome to quadratic equation solver (ax^2 + bx + c = 0)\n\n");

    const double a = getDouble("Enter first coefficient (a): " );
    const double b = getDouble("Enter second coefficient (b): ");
    const double c = getDouble("Enter third coefficient (c): " );

    double x1 = NAN, x2 = NAN;
    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);

    switch (rootsNumber) {
        case 0:
            printf("No roots\n");
            break;
        case 1:
            printf("One root: x = %lg\n", x1);
            break;
        case 2:
            printf("Two roots: x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case SOLVER_INFINITE_ROOTS:
            printf("Infinite number of roots\n");
            break;
        case SOLVER_NOT_SOLVED:
            printf("Sorry, the equation can't be solved :C \n");
            break;
        default:
            fprintf(stderr, "ERROR OCCURRED!\n\trootsNumber = %d\n", rootsNumber);
            return -1;
    }

    return 0;
}
