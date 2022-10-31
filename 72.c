#include <stdio.h>
#include <assert.h>

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

int main()
{
    int array[100][100], check[100][100];
    const int *ptr_array[100][100];
    int i, j, m;

    scanf("%d", &m);
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++) {
            ptr_array[i][j] = &(array[i][j]);
            scanf("%d", &(array[i][j]));
            check[i][j] = array[i][j];
    }

    snake(ptr_array, m);

    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            
            printf("%d ", *(ptr_array[i][j]));
        }
    printf("\n");
    }

return 0;
}