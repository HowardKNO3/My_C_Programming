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

int main(int argc, char const *argv[])
{
    int N, k;
    scanf("%d%d", &N, &k);
    int A[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
    int *a[N], *head[k];
    for (int i = 0; i < N-1; ++i)
        a[i] = &A[i+1];
    a[N-1] = NULL;
    for (int i = 0; i < k; ++i)
        head[i] = NULL;
    split(A, a, head, k);
    for (int i = 0; i < k; ++i) {
        if (head[i] == NULL)
            printf("NULL\n");
        else {
            int *tmp = head[i];
            printf("%d", *tmp);
            tmp = *(tmp-A+a);
            while (tmp != NULL) {
                printf(" %d", *tmp);
                tmp = *(tmp-A+a);
            }
            printf("\n");
        }
    }
    return 0;
}