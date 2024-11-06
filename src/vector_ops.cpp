#include "neoncore/vector_ops.h"
#include <arm_neon.h> // NEON intrinsics for ARM SIMD

namespace neoncore {

// ==============================
// Implementation of vector operations
// ==============================

// Add two float arrays element-wise and store the result in a third array.
// This function processes 4 elements at a time using NEON SIMD instructions.
void add_float_arrays(float* result, const float* a, const float* b, size_t size) {
    size_t i = 0;

    // Process 4 elements at a time
    for (; i + 4 <= size; i += 4) {
        // Load 4 floats from each array into NEON registers
        float32x4_t va = vld1q_f32(&a[i]);  // Load from 'a'
        float32x4_t vb = vld1q_f32(&b[i]);  // Load from 'b'

        // Add the two vectors (element-wise)
        float32x4_t vresult = vaddq_f32(va, vb);

        // Store the result back into the 'result' array
        vst1q_f32(&result[i], vresult);
    }

    // Handle any remaining elements (less than 4)
    for (; i < size; ++i) {
        result[i] = a[i] + b[i];
    }
}

} // namespace neoncore
