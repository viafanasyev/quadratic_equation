/**
 * @file
 */
#include "testlib.h"
#include "../src/solver.h"

TEST(solveLinear, oneRoot) {
    const double a = 2, b = 3;
    double x = NAN;

    const int rootsNumber = solveLinear(a, b, x);
    ASSERT_EQUALS(rootsNumber, 1);
    ASSERT_DOUBLE_EQUALS(x, -b / a);
}

TEST(solveLinear, oneRoot_withZeroSecondCoefficient) {
    const double a = 2, b = 0;
    double x = NAN;

    const int rootsNumber = solveLinear(a, b, x);
    ASSERT_EQUALS(rootsNumber, 1);
    ASSERT_DOUBLE_EQUALS(x, -b / a);
}

TEST(solveLinear, noRoots) {
    const double a = 0, b = 3;
    double x = NAN;

    const int rootsNumber = solveLinear(a, b, x);
    ASSERT_EQUALS(rootsNumber, 0);
}

TEST(solveLinear, infiniteRoots) {
    double a = 0, b = 0;
    double x = NAN;

    const int rootsNumber = solveLinear(a, b, x);
    ASSERT_EQUALS(rootsNumber, SOLVER_INFINITE_ROOTS);
}

TEST(solveLinear, normalizationExpected) {
    const double a = 0.1 * SOLVER_EPS, b = 0.1 * SOLVER_EPS;
    double x = NAN;

    const int rootsNumber = solveLinear(a, b, x);
    ASSERT_EQUALS(rootsNumber, 1);
    ASSERT_DOUBLE_EQUALS(x, -b / a);
}
