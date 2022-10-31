#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXLEN 35

bool same_word (char a, char b) {
    return a == b;
}

int main () {
    char prev_word[MAXLEN] = {};
    char now_word[MAXLEN] = {};
    scanf("%s", &prev_word);
    int mode = -1;
    int now_width = strlen(prev_word);
    printf("%s\n", prev_word);
    while (scanf("%s", &now_word) != EOF) {
        int prev_len = strlen(prev_word);
        int len = strlen(now_word);
        if (mode == 1) {
            if (!same_word(prev_word[prev_len - 1], now_word[0])) {
                printf("%c\n", prev_word[prev_len - 1]);
                for (int i = 0; i < now_width - 1; i++) {
                    printf("*");
                }
            }
            printf("%s\n", now_word);
            now_width += len - 1;
        } else {
            for (int i = 0; i < len; i++) {
                if (same_word(prev_word[prev_len - 1], now_word[0]) && i == 0) {
                    continue;
                } 
                for (int i = 0; i < now_width - 1; i++) {
                    printf("*");
                }
                if (i != len - 1) {
                    printf("%c\n", now_word[i]);
                }
            }
        }
        mode *= -1;
        strcpy(prev_word, now_word);
    }
    if (mode == 1) {
        printf("%c\n", prev_word[strlen(prev_word) - 1]);
    }
}