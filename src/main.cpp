#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

// Math libraries
#include "imath.h"
#include "smath.h"
#include <mkl.h>

static inline void randomVector(std::vector<float> &vec, int upperBound) {
    for (size_t i = 0; i < vec.size(); i++) { vec[i] = rand() % upperBound; }
}

void benchmark() {
    srand(time(NULL));

    /* Common inputs 3x8 */
    std::vector<float> in_a(24);
    std::vector<float> w_a(24);
    float *in_a_f = &in_a[0];
    float *w_a_f = &w_a[0];

    randomVector(in_a, 50);
    randomVector(w_a, 50);

    /* Scalar way */
    float man_result = 0.0f;
    auto man_start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++) {
        man_result = SCALAR::dotProd<std::vector<float>>(in_a, w_a);
    }
    auto man_end = std::chrono::high_resolution_clock::now();
    auto man_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
        man_end - man_start);

    /* AVX way */
    float avx_result = 0.0f;
    auto avx_start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++) {
        avx_result = iAVX::avx_dot_product(in_a, w_a);
    }
    auto avx_end = std::chrono::high_resolution_clock::now();
    auto avx_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
        avx_end - avx_start);

    /* MKL way */
    float mkl_result = 0.0f;
    auto mkl_start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100; i++) {
        mkl_result = cblas_sdot(24, in_a_f, 1, w_a_f, 1);
    }
    auto mkl_end = std::chrono::high_resolution_clock::now();
    auto mkl_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(
        mkl_end - mkl_start);

    /* Show results */
    std::cout << "Manual Result: " << man_result << std::endl;
    std::cout << "Manual Time: " << man_duration.count() << " nanoseconds"
              << std::endl;
    std::cout << "AVX Result: " << avx_result << std::endl;
    std::cout << "AVX Time: " << avx_duration.count() << " nanoseconds"
              << std::endl;
    std::cout << "MKL Result: " << mkl_result << std::endl;
    std::cout << "MKL Time: " << mkl_duration.count() << " nanoseconds"
              << std::endl;
}

int main() {
    // /* Ensure dimensions are compatible and multiple of 8 for AVX */
    // if (in_a.size() != w_a.size() || w_a.size() % 8 != 0) {
    //     throw std::runtime_error("Incompatible matrix dimensions");
    // }

    benchmark();

    return 0;
}
