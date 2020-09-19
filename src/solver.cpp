/**
 * @file
 * @brief Source file with equation solver implementation
 */
#include "solver.h"
#include <cmath>
#include <cassert>

/**
 * Checks if a number is roughly equal to zero.
 * @param[in] x number to check
 * @return true, if number is almost a zero, false otherwise.
 */
inline static bool isZero(double x) {
    assert(std::isfinite(x));

    return fabs(x) < SOLVER_EPS;
}

/**
 * Gets rid of negative zero.
 * @param x value to round
 * @return 0, if the value is negative zero, or the actual value.
 */
inline static double roundNegativeZero(double x) {
    assert(std::isfinite(x));

    return isZero(x) ? 0 : x;
}

/**
 * Solves the linear equation ax + b == 0.
 * @param[in]  a first coefficient
 * @param[in]  b second coefficient
 * @param[out] x root of this equation
 * @return number of roots,
 *         or SOLVER_INFINITE_ROOTS, if any number can be a solution,
 *         or SOLVER_NOT_SOLVED, if the equation can't be solved for technical/mathematical reasons.
 */
int solveLinear(double a, double b, double& x) {
    if (!std::isfinite(a) || !std::isfinite(b)) {
        return SOLVER_NOT_SOLVED;
    }

    if (isZero(a)) {
        return isZero(b) ? SOLVER_INFINITE_ROOTS : 0;
    }

    x = roundNegativeZero(-b / a);
    return 1;
}

/**
 * Solves the quadratic equation ax^2 + bx + c == 0. If there are two roots, they are sorted by ascending order.
 *
 * @note If the first coefficient is equal to zero, solveLinear function is used to solve this equation.
 *
 * @param[in]  a  first coefficient
 * @param[in]  b  second coefficient
 * @param[in]  c  third coefficient
 * @param[out] x1 first root of this equation
 * @param[out] x2 second root of this equation
 * @return number of roots,
 *         or SOLVER_INFINITE_ROOTS, if any number can be a solution,
 *         or SOLVER_NOT_SOLVED, if the equation can't be solved for technical/mathematical reasons.
 */
int solveQuadratic(double a, double b, double c, double& x1, double& x2) {
    if (!std::isfinite(a) || !std::isfinite(b) || !std::isfinite(c)) {
        return SOLVER_NOT_SOLVED;
    }

    assert(&x1 != &x2);

    if (isZero(a)) {
        return solveLinear(b, c, x1);
    }

    double d = b * b - 4 * a * c;
    if (!std::isfinite(d)) {
        return SOLVER_NOT_SOLVED;
    }

    if (isZero(d)) {
        x1 = x2 = roundNegativeZero(-b / (2 * a));
        return 1;
    }

    if (d > 0) {
        x1 = roundNegativeZero((-b - sqrt(d)) / (2 * a));
        x2 = roundNegativeZero((-b + sqrt(d)) / (2 * a));
        if (a < 0) std::swap(x1, x2); // to sort x1 and x2 by ascending order
        return 2;
    }

    return 0; // if (d < 0)
}
