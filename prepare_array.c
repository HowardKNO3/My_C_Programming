#include <stdio.h>
#include "prepare_array.h"
#define INF 1000000000

void prepare_array(int buffer[], int *array[], int row, int column[]) {
    int total = 0;
    for (int i = 0; i < 10000; i++) {
        buffer[i] = 0;
    }
    for (int i = 0; i < row; i++) {
        array[i] = &(buffer[total]);
        total += column[i];
    }
    for (int i = 0; i < total; i++) {
        if (i % 2 == 0) {
            buffer[i] = 0;
        } else {
            buffer[i] = 1;
        }
    }
    return;
}