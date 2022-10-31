#include <stdio.h>
#include <string.h>
#include "fill_rectangle.h"
void fill_rectangle_neg(int *upper_left, int *bottom_right, int n_row, int n_col, int fill) {
    int diff = bottom_right - upper_left;
    int row = diff / n_col;
    int col = diff % n_col;
    //printf("%d %d %d %d\n", diff, row, col, *upper_left);
    
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= col; j++) {
            *(upper_left + (n_col * i + j)) = fill;
        }
    }
    
    return;
}
void fill_rectangle_pos(int *upper_right, int *bottom_left, int n_row, int n_col, int fill) {
    int diff = bottom_left - upper_right;
    int row, col;
    if (diff > 0) {
        row = diff / n_col;
        col = n_col - diff % n_col;
        if (col == n_col) {
            col = 0;
        } else {
            row++;
        }
    } else {
        row = 0;
        col = -diff % n_col;
    }
    //printf("%d %d %d\n", row, col, diff);
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= col; j++) {
            *(upper_right + (n_col * i - j)) = fill;
        }
    }
}