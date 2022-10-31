#include <stdio.h>
#include <stdlib.h>
#include "findRowAndColumn.h"
#define MAXN 105

void findRowAndColumn(int **ptr, int *Row, int *Col, int **start, int *ansRow, int *ansCol) {
    int index = 0;
    while (ptr[index] != NULL)
    {
        int diff = (ptr[index] - start[index]);
        ansRow[index] = diff / Col[index];
        ansCol[index] = diff % Col[index];
        
        //printf("%d\n", diff);
        index++;
        
    }
    
}