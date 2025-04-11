/** @file imath.h
 *  @brief AVX optimized math functions
 *  @author Vasileios Ch. (BillisC)
 *  @bug None yet
 */

#ifndef IMATH_H
#define IMATH_H

/**
 *  @brief Required headers for functions below
 */
#include <immintrin.h>
#include <iostream>
#include <cstdint>
#include <vector>

namespace iAVX {

/**
 *  @brief DP with AVX
 *
 *  Calculates the dot product of two SP
 *  vectors using AVX instructions.
 *
 *  @param a First vector
 *  @param b Second vector
 *  @return Result of math operation
 */
static inline float avx_dot_product(std::vector<float> &a,
                                    std::vector<float> &b) {
    const uint8_t elements = a.size();

    /* Initialize sum register to zero */
    __m256 sum_vec = _mm256_setzero_ps();

    /* Process 8 elements at a time */
    for (uint8_t y = 0; y < elements; y += 8) {
        /* Load 8 floats from each matrix */
        const __m256 va = _mm256_loadu_ps(&a[y]);
        const __m256 vb = _mm256_loadu_ps(&b[y]);

        /* Multiply and accumulate */
        const __m256 mul_result = _mm256_mul_ps(va, vb);
        sum_vec = _mm256_add_ps(sum_vec, mul_result);
    }

    /* Horizontal Reduction */
    __m128 sum128 = _mm_add_ps(_mm256_castps256_ps128(sum_vec),
                               _mm256_extractf128_ps(sum_vec, 1));
    sum128 = _mm_add_ps(
        sum128, _mm_shuffle_ps(sum128, sum128, _MM_SHUFFLE(1, 0, 3, 2)));
    sum128 = _mm_add_ss(
        sum128, _mm_shuffle_ps(sum128, sum128, _MM_SHUFFLE(0, 0, 0, 1)));

    /* Store result */
    float result;
    _mm_store_ss(&result, sum128);

    return result;
}

} // namespace iAVX

#endif
