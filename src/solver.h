/**
 * @file
 * @brief Header file with expression solver description
 */
#ifndef QUADRATIC_EQUATION_SOLVER_H
#define QUADRATIC_EQUATION_SOLVER_H

#include <cstdint>

/** Constant to describe if there are infinite solutions in equation. **/
#define SOLVER_INFINITE_ROOTS INT32_MAX

/** Precision for checking equality with zero. **/
#define SOLVER_EPS 1e-9

/**
 * Solves the linear equation ax + b == 0.
 * @param[in]  a first coefficient
 * @param[in]  b second coefficient
 * @param[out] x root of this equation
 * @return number of roots, or SOLVER_INFINITE_ROOTS, if any number can be a solution.
 */
int solveLinear(double a, double b, double& x);

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
 * @return number of roots, or SOLVER_INFINITE_ROOTS, if any number can be a solution.
 */
int solveQuadratic(double a, double b, double c, double& x1, double& x2);

#endif //QUADRATIC_EQUATION_SOLVER_H
