#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXLEN 10005

bool is_vowel (char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main () {
    char input[MAXLEN];
    while (scanf("%s", &input) != EOF)
    {
        int vowel_count = 0;
        int vowel_indices[MAXLEN] = {};
        int len = strlen(input);
        vowel_indices[0] = -1;
        for (int i = 0; i < len; i++) {
            if (is_vowel(input[i])) {
                vowel_indices[vowel_count + 1] = i;
                vowel_count++;
            }
        }
        int syl_1, syl_2;
        scanf("%d%d", &syl_1, &syl_2);
        for (int i = 0; i <= vowel_indices[syl_1]; i++) {
            printf("+");
        }
        for (int i = vowel_indices[syl_1] + 1; i <= vowel_indices[syl_1 + 1]; i++) {
            printf("%c", input[i]);
        }
        for (int i = vowel_indices[syl_1 + 1] + 1; i < len; i++) {
            printf("+");
        }
        printf("\n");
        for (int i = 0; i <= vowel_indices[syl_2]; i++) {
            printf("+");
        }
        for (int i = vowel_indices[syl_2] + 1; i <= vowel_indices[syl_2 + 1]; i++) {
            printf("%c", input[i]);
        }
        for (int i = vowel_indices[syl_2 + 1] + 1; i < len; i++) {
            printf("+");
        }
        printf("\n");
        for (int i = 0; i < len; i++) {
            if ((i >= vowel_indices[syl_1] + 1 && i <= vowel_indices[syl_1 + 1]) || (i >= vowel_indices[syl_2] + 1 && i <= vowel_indices[syl_2 + 1])) {
                printf("+");
            } else {
                printf("%c", input[i]);
            }
        }
        printf("\n");
    }
    
}