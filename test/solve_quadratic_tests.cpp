/**
 * @file
 */
#include "testlib.h"
#include "../src/solver.h"

TEST(solveQuadratic, twoRoots1) {
    // (x - 1)(x - 3) = x^2 - 4x + 3
    const double a = 1, b = -4, c = 3;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 2);
    ASSERT_DOUBLE_EQUALS(x1, 1);
    ASSERT_DOUBLE_EQUALS(x2, 3);
}

TEST(solveQuadratic, twoRoots2) {
    // (x - 0)(x - 3) = x^2 - 3x + 0
    const double a = 1, b = -3, c = 0;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 2);
    ASSERT_DOUBLE_EQUALS(x1, 0);
    ASSERT_DOUBLE_EQUALS(x2, 3);
}

TEST(solveQuadratic, twoRoots3) {
    // -(x - 1)(x - 3) = -x^2 + 4x - 3
    const double a = -1, b = 4, c = -3;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 2);
    ASSERT_DOUBLE_EQUALS(x1, 1);
    ASSERT_DOUBLE_EQUALS(x2, 3);
}

TEST(solveQuadratic, twoRoots4) {
    // -(x - 0)(x - 3) = -x^2 + 3x - 0
    const double a = -1, b = 3, c = 0;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 2);
    ASSERT_DOUBLE_EQUALS(x1, 0);
    ASSERT_DOUBLE_EQUALS(x2, 3);
}

//----------------------------------------------------------------------------------------------------------------------

TEST(solveQuadratic, oneRoot1) {
    // (x - 2)(x - 2) = x^2 - 4x + 4
    const double a = 1, b = -4, c = 4;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 1);
    ASSERT_DOUBLE_EQUALS(x1, 2);
    ASSERT_DOUBLE_EQUALS(x2, 2);
}

TEST(solveQuadratic, oneRoot2) {
    // -(x - 2)(x - 2) = -x^2 + 4x - 4
    const double a = -1, b = 4, c = -4;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 1);
    ASSERT_DOUBLE_EQUALS(x1, 2);
    ASSERT_DOUBLE_EQUALS(x2, 2);
}

TEST(solveQuadratic, oneRoot3) {
    // (x - 0)(x - 0) = x^2
    const double a = 1, b = 0, c = 0;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 1);
    ASSERT_DOUBLE_EQUALS(x1, 0);
    ASSERT_DOUBLE_EQUALS(x2, 0);
}

TEST(solveQuadratic, oneRoot4) {
    // -(x - 0)(x - 0) = -x^2
    const double a = -1, b = 0, c = 0;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 1);
    ASSERT_DOUBLE_EQUALS(x1, 0);
    ASSERT_DOUBLE_EQUALS(x2, 0);
}

//----------------------------------------------------------------------------------------------------------------------

TEST(solveQuadratic, noRoots) {
    // x^2 - 4x + 5 => d = (-4)^2 - 4*1*5 = -4
    const double a = 1, b = -4, c = 5;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 0);
}

//----------------------------------------------------------------------------------------------------------------------

TEST(solveQuadratic, linear_oneRoot1) {
    const double a = 0, b = 2, c = 3;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 1);
    ASSERT_DOUBLE_EQUALS(x1, -c / b);
}

TEST(solveQuadratic, linear_oneRoot2) {
    const double a = 0, b = 2, c = 0;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 1);
    ASSERT_DOUBLE_EQUALS(x1, -c / b);
}

TEST(solveQuadratic, linear_noRoots) {
    const double a = 0, b = 0, c = 3;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, 0);
}

TEST(solveQuadratic, linear_infiniteRoots) {
    const double a = 0, b = 0, c = 0;
    double x1 = NAN, x2 = NAN;

    const int rootsNumber = solveQuadratic(a, b, c, x1, x2);
    ASSERT_EQUALS(rootsNumber, SOLVER_INFINITE_ROOTS);
}
