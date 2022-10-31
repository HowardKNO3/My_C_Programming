#include <stdio.h>
#define MAXN 105

void rotate (int layer[MAXN][MAXN], int n) {
    int new_layer[MAXN][MAXN] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            new_layer[j][n - 1 - i] = layer[i][j];
            //printf("%d ", layer[i][j]);
        }
        //printf("\n");
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            layer[i][j] = new_layer[i][j];
        }
    }
}



void rotate_0 (int cube[MAXN][MAXN][MAXN], int n, int choose) {
    int layer[MAXN][MAXN] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            layer[i][j] = cube[choose][i][j]; 
            //printf("%d ", layer[i][j]);
        }
        //printf("\n");
    }
    rotate(layer, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cube[choose][i][j] = layer[i][j];
        }
    }
}

void rotate_1 (int cube[MAXN][MAXN][MAXN], int n, int choose) {
    int layer[MAXN][MAXN] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            layer[i][j] = cube[i][j][choose]; 
            //printf("%d ", layer[i][j]);
        }
        //printf("\n");
    }
    rotate(layer, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cube[i][j][choose] = layer[i][j];
        }
    }
}

int main () {
    int cube[MAXN][MAXN][MAXN] = {0};
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cube[i][j][k] = i * n * n + j * n + k;
                
            }
        }
    }
    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%d ", cube[i][j][k]);
            }
            printf("\n");
        }
    }
    */
    for (int i = 0; i < m; i++) {
        int type, choose;
        scanf("%d%d", &type, &choose);
        if (type == 0) {
            rotate_0(cube, n, choose);
        } else {
            rotate_1(cube, n, choose);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                printf("%d ", cube[i][j][k]);
            }
            printf("\n");
        }
    }
}