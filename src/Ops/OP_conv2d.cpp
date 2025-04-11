/** @file OP_conv2d.cpp
 *  @brief 2D convolution OP
 *  @author Vasileios Ch. (BillisC)
 *  @bug None yet
 */

#include "OP_conv2d.h"

std::vector<float> OP_conv2d::forward() { return std::vector<float>(0); }

OP_conv2d::OP_conv2d(std::vector<float> *input, std::vector<float> *weights,
                     const conv2d_k &kernel, const uint32_t &input_x,
                     const uint32_t &input_y)
    : input(input), weights(weights), kernel(kernel), input_x(input_x),
      input_y(input_y) {
    std::cout << "Initialized Conv2D function" << std::endl;
}
