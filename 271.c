#include <stdio.h>

int main () {
    int n1, n2;
    scanf("%d", &n1);
    int poly_1[n1];
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &poly_1[i]);
    }
    scanf("%d", &n2);
    int poly_2[n2];
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &poly_2[i]);
    }
    for (int i = 0; i < n1 / 2; i++)
    {
        int temp = poly_1[i];
        poly_1[i] = poly_1[n1 - i - 1];
        poly_1[n1 - i - 1] = temp;
    }
    for (int i = 0; i < n2 / 2; i++)
    {
        int temp = poly_2[i];
        poly_2[i] = poly_2[n2 - i - 1];
        poly_2[n2 - i - 1] = temp;
    }
    int result[n1 + n2 - 1];
    for (int i = 0; i < n1 + n2 - 1; i++)
    {
        result[i] = 0;
    }
    
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
           result[i + j] += poly_1[i] * poly_2[j];
        }
        
    }
    for (int i = n1 + n2 - 2; i >= 1; i--) {
        printf("%d ", result[i]);
    }
    printf("%d", result[0]);
    
}