#include <stdio.h>
#include "evaluate_f.h"
#define INF 1000000000

int evaluate_f(int *iptr[], int n, int *index) {
    int now_max = -INF;
    for (int i = 0; i < n; i++) {
        int cur = *(iptr[i]) * 4 - *(iptr[i] + 1) * 6;
        if (cur > now_max) {
            now_max = cur;
            *index = i;
        }
    }
    return now_max;
}
int main () {
    int row = 4;
    int column[4] = {10, 20, 30, 10};
    int *array[50];
    int buffer[10000];
    prepare_array(buffer, array, row, column);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < column[i]; j++)
            array[i][j] = i * 100 + j;
    return 0;
}