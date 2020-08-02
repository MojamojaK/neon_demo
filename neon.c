#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <arm_neon.h>

#ifndef __ARM_NEON_FP
#error "NEON FP UNAVAILABLE"
#endif

#define SIZE 1024

int main(void) {
    float a[SIZE] __attribute__((aligned(16)));
    float b[SIZE] __attribute__((aligned(16)));
    float c[SIZE] __attribute__((aligned(16)));
    
    srand((signed)time(NULL));
    for (long long i = 0ll; i < SIZE; i++) {
        a[i] = (float)rand();
        b[i] = (float)rand(); 
    }

    for (long long i = 0ll; i < SIZE; i += 4) {
        float32x4_t va = vld1q_f32(a + i);
        float32x4_t vb = vld1q_f32(b + i);
        float32x4_t vc = vaddq_f32(va, vb);
        vst1q_f32(c + i, vc);
    }

    for (long long i = 0ll; i < SIZE; i++) {
        if (c[i] != a[i] + b[i]) {
            return 1;
        }
    }

    return 0;
}
