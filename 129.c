#include <stdio.h>
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