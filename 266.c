#include <stdio.h>
#include <string.h>
#define MAXN 105
#define MAXLEN 15

int min (int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int edit_distance(char s1[MAXLEN], char s2[MAXLEN], int len_1, int len_2, int index_1, int index_2) {
    if (index_1 == len_1) {
        return len_2 - index_2;
    }
    if (index_2 == len_2) {
        return len_1 - index_1;
    }
    if (s1[index_1] == s2[index_2]) {
        return edit_distance(s1, s2, len_1, len_2, index_1 + 1, index_2 + 1);
    }
    return 1 + min(edit_distance(s1, s2, len_1, len_2, index_1 + 1, index_2), 
    edit_distance(s1, s2, len_1, len_2, index_1, index_2 + 1));
}

int main () {
    char strings[MAXN][MAXLEN] = {};
    int size = 0;
    while (scanf("%s", strings[size]) != EOF)
    {
        size++;
        
    }
    int id = 0;
    int min_distance = 20;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            int len_1 = strlen(strings[i]); 
            int len_2 = strlen(strings[j]); 
            int dist = edit_distance(strings[i], strings[j], len_1, len_2, 0, 0);
            if (dist < min_distance) {
                id = (i + 1) * 1000 + (j + 1);
                min_distance = dist;
            }
        }
    }
    printf("%d %d %d\n", min_distance, id / 1000, id % 1000);
    //printf("%d", edit_distance(strings[2], strings[3], strlen(strings[2]), strlen(strings[3]), 0, 0));
}