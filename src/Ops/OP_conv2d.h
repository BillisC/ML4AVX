/** @file OP_conv2d.h
 *  @brief 2D convolution OP
 *  @author Vasileios Ch. (BillisC)
 *  @bug None yet
 */

#ifndef OP_conv2d_H
#define OP_conv2d_H

#include "Ops/OP_base.h"
#include <iostream>
#include <cstdint>
#include <vector>

struct conv2d_k {
    const uint16_t n_filters; /* Number of filters */
    const uint16_t k_size;    /* Size of kernel (e.g. 3 = 3x3) */
    const uint16_t stride;    /* Stride of the kernel */
};

class OP_conv2d : OP_base {
  public:
    std::vector<float> forward() override;
    OP_conv2d(std::vector<float> *input, std::vector<float> *weights,
              const conv2d_k &kernel, const uint32_t &input_x,
              const uint32_t &input_y);

  private:
    std::vector<float> *input, *weights;
    const conv2d_k kernel;
    const uint32_t input_x, input_y;
};

#endif