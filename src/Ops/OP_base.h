/** @file OP_base.h
 *  @brief The base abstract class of all OPs
 *  @author Vasileios Ch. (BillisC)
 *  @bug None yet
 */

#ifndef OP_base_H
#define OP_base_H

#include <vector>

class OP_base {
  public:
    virtual std::vector<float> forward() = 0;
    virtual void load(float *weights) = 0;
};

#endif