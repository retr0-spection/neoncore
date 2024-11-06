#ifndef NEONCORE_VECTOR_OPS_H
#define NEONCORE_VECTOR_OPS_H

#include <cstddef> // For size_t

namespace neoncore {

// ==============================
// Vector Operations Interface
// ==============================

// Add two float arrays element-wise and store the result in a third array.
// This function processes 4 elements at a time using NEON SIMD instructions.
void add_float_arrays(float* result, const float* a, const float* b, size_t size);

} // namespace neoncore

#endif // NEONCORE_VECTOR_OPS_H
