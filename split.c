#include <stdio.h>
#include <stdlib.h>

void split(int A[], int *a[], int *head[], int k) {
    int **tail[k];
    for (int i = 0; i < k; i++) {
        tail[i] = &head[i];
    }
    int size = 1;
    while (a[size - 1] != NULL)
    {
        size++;
    }
    for (int i = 0; i < size; i++) {
        a[i] = NULL;
    }
    for (int i = 0; i < size; i++) {
        int remainder = A[i] % k;
        *tail[remainder] = &A[i];
        tail[remainder] = &a[i];
    }
    
}