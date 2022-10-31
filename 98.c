#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXN 300
#define MAXM 20
#define MAXLEN 200

int find (char string[MAXLEN], char table[MAXN][MAXLEN]) {
    int i = 0;
    while (table[i] != NULL) {
        //printf("%s\n", table[i]);
        if (strcmp(string, table[i]) == 0) {
            return i;
        }
        i++;
        //printf("%d\n", i);
    }
    return -1;
}

int main () {
    int n;
    char table[MAXN][MAXLEN] = {};
    char ingredients[MAXN][MAXM][MAXLEN] = {};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        /*
        for (int j = 0; j < i; j++) {
            printf("%s\n", table[j]);
        }
        */
        char food[MAXLEN] = "";
        scanf("%s", &table[i]);

        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%s", &ingredients[i][j]);
        }
    }
    /*
    for (int j = 0; j < n; j++) {
        printf("%d %s\n", j, table[j]);
    }
    */
    int q;
    
    scanf("%d", &q);
    for (int qq = 0; qq < q; qq++) {
        char s1[MAXLEN], s2[MAXLEN];
        scanf("%s%s", &s1, &s2);
        int food_1 = find(s1, table);
        int food_2 = find(s2, table);
        
        int cnt = 0;
        char same[MAXM][MAXLEN] = {};
        //printf("%d\n", qq);
        //printf("%d %d\n", food_1, food_2);
        //printf("%d", strcmp(s1 == table[i]));
        for (int i = 0; strcmp(ingredients[food_1][i], "") != 0; i++) {
            for (int j = 0; strcmp(ingredients[food_2][j], "") != 0; j++) {
                //printf("%d %d %s %s\n", i, j, ingredients[food_1][i], ingredients[food_2][j]);
                if (strcmp(ingredients[food_1][i], ingredients[food_2][j]) == 0) {
                    strcpy(same[cnt], ingredients[food_1][i]);
                    cnt++;
                }
            }
        }
        if (cnt == 0) {
            printf("nothing");
        } else {
            char *same_ptr[cnt];
            for (int i = 0; i < cnt; i++) {
                same_ptr[i] = same[i];
            }
            
            for (int i = cnt - 1; i >= 0; i--) {
                for (int j = 0; j < i; j++) {
                    
                    if (strcmp(same_ptr[j], same_ptr[j + 1]) > 0) {
                        char *temp = same_ptr[j];
                        same_ptr[j] = same_ptr[j + 1];
                        same_ptr[j + 1] = temp;
                    }
                    
                }
            }
            
            for (int i = 0; i < cnt; i++) {
                printf("%s", same_ptr[i]);
                if (i != cnt - 1) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    
}