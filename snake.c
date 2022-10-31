#include <stdio.h>
#include <assert.h>
#include "snake.h"

int get_column (int index, int m) {
    int row = index / m;
    if (row % 2 == 0) {
        return index % m;
    } else {
        return m - 1 - index % m;
    }
}

void snake(const int *ptr_array[100][100], int m) {
    for (int i = m * m; i >= 1; i--) {
        for (int j = 0; j < i - 1; j++) {
            //printf("%d\n", j);
            if (*(ptr_array[j / m][get_column(j, m)]) > *(ptr_array[(j + 1) / m][get_column(j + 1, m)])) {
                //printf("%d %d %d\n", j, j / m, get_column(j, m));
                
                const int *temp = ptr_array[j / m][get_column(j, m)];
                
                ptr_array[j / m][get_column(j, m)] = ptr_array[(j + 1) / m][get_column(j + 1, m)];
                ptr_array[(j + 1) / m][get_column(j + 1, m)] = temp;
                
            }
        }
    }
    return;
}
