#include <stdio.h>
#include <stdbool.h>
#define INF 1000000000
void merge(int A[], int B[], int* a[], int* b[]){
    int a_index = 0, b_index = 0;
    int a_size = 0, b_size = 0;

    while (a[a_size] != NULL)
    {
        a_size++;
    }
    a_size++;
    while (b[b_size] != NULL)
    {
        b_size++;
        
    }
    b_size++;
    int point_to = 0;
    while (a_index < a_size && b_index < b_size)
    {
        
        
        if (A[a_index] < B[b_index]) {
            if ((a_index + 1 < a_size) && A[a_index + 1] < B[b_index]) {
                a[a_index] = &A[a_index + 1];
            } else {
                a[a_index] = &B[b_index];
            }
            point_to = *a[a_index];
            a_index++;
        } else {
            if ((b_index + 1 < b_size) && B[b_index + 1] < A[a_index]) {
                b[b_index] = &B[b_index + 1];
            } else {
                b[b_index] = &A[a_index];
            }
            point_to = *b[b_index];
            b_index++;
        }
    }
    if (a_index == a_size) {
        for (int i = b_index; i < b_size - 1; i++) {
            b[i] = &B[i + 1];
        }
    }
    else if (b_index == b_size) {
        for (int i = a_index; i < a_size - 1; i++) {
            a[i] = &A[i + 1];
        }
    }
}