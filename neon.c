#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 1024

int main(void) {
    float a[SIZE], b[SIZE], c[SIZE];
    
    srand((signed)time(NULL));
    for (long long i = 0ll; i < SIZE; i++) {
        a[i] = (float)rand();
        b[i] = (float)rand(); 
    }

    for (long long i = 0ll; i < SIZE; i++) {
        c[i] = a[i] + b[i];
    }

    for (long long i = 0ll; i < SIZE; i++) {
        if (c[i] != a[i] + b[i]) {
            return 1;
        }
    }

    return 0;
}
