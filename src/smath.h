/** @file smath.h
 *  @brief Scalar math functions
 *  @author Vasileios Ch. (BillisC)
 *  @bug None yet
 */

#ifndef SMATH_H
#define SMATH_H

namespace SCALAR {

/**
 *  @brief DP template function
 *
 *  Calculates the dot product of two SP
 *  vectors.
 *
 *  @param a First vector
 *  @param b Second vector
 *  @return Result of math operation
 */
template <typename T> static inline float dotProd(T &arr_a, T &arr_b) {
    const int elements = arr_a.size();

    float result = 0.0f;
    for (int i = 0; i < elements; i++) { result += arr_a[i] * arr_b[i]; }

    return result;
}

} // namespace SCALAR

#endif