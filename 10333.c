#include <stdio.h>
#include <string.h>
#define MAXN 100
#define MAXC 10

char input[MAXN][MAXN][MAXN][6] = {};
char string_hash_table[MAXN * MAXN][MAXC][6] = {};
int value_hash_table[MAXN * MAXN][MAXC][2] = {};
int pointer[MAXN][MAXN] = {};
int min (int a, int b) {
    return (a < b) ? a : b;
}

int max (int a, int b) {
    return (a > b) ? a : b;
}

int hash_function (char* s) {
    int sum = 0;
    int index = 0;
    while (s[index] != '\0') {
        sum *= 29;
        sum += (s[index] - 'a' + 1);
        index++;
    }
    return sum % (MAXN * MAXN);
}


void hash_table_check (int n, int now_ptr, int now_x, int now_y) {
    
    char cur[6];
    strcpy(cur, input[now_ptr][now_x][now_y]);
    int hash = hash_function(cur);
    int min_index = MAXC;
    for (int i = 0; i < MAXC; i++) {
        
        if (strcmp(string_hash_table[hash][i], "") == 0) {
            min_index = min(min_index, i);
        }
        if (strcmp(string_hash_table[hash][i], cur) == 0) {
            printf("%s\n", cur);
            int another_x = value_hash_table[hash][i][0];
            int another_y = value_hash_table[hash][i][1];
            pointer[now_x][now_y]++;
            pointer[another_x][another_y]++;
            strcpy(string_hash_table[hash][i], "");
            value_hash_table[hash][i][0] = 0;
            value_hash_table[hash][i][1] = 0;
            if (pointer[now_x][now_y] < n) hash_table_check(n, pointer[now_x][now_y], now_x, now_y);
            if (pointer[another_x][another_y] < n) hash_table_check(n, pointer[another_x][another_y], another_x, another_y);
            return;
        }


    }
    //printf("%d %d\n", hash, min_index);   
    strcpy(string_hash_table[hash][min_index], cur);
    value_hash_table[hash][min_index][0] = now_x;
    value_hash_table[hash][min_index][1] = now_y;
    //printf("%d\n", cnt);
    /*
    for (int i = 0; i < MAXN * MAXN; i++) {
        for (int j = 0; j < MAXC; j++) {
            printf("%d ", hash_table[i][j][0]);
        }
        printf("\n");
    }
    */

    return;
}

int main () {
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pointer[i][j] = max(i, j);
        }
    }
    //printf("%d %d", get_index(10), get_layer(10));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= i; k++) {
                scanf("%s", input[i][j][k]);
                //printf("%d %d %s\n", j, k, input[i][j][k]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hash_table_check(n, pointer[i][j], i, j);
        }
    }
}
