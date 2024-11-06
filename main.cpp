#include <arm_neon.h>
#include <iostream>

int main() {
    // Define two arrays of four 32-bit integers
    int32_t a[4] = {1, 2, 3, 4};
    int32_t b[4] = {5, 6, 7, 8};
    int32_t result[4];

    // Load data into NEON registers
    int32x4_t va = vld1q_s32(a);
    int32x4_t vb = vld1q_s32(b);

    // Perform SIMD addition
    int32x4_t vresult = vaddq_s32(va, vb);

    // Store the result back to memory
    vst1q_s32(result, vresult);

    // Output the results
    for (int i = 0; i < 4; ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}
