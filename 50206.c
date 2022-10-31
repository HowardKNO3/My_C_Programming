#include <stdio.h>
#include <string.h>
#define MAXLEN 100
int main () {
    int table[26][26][26] = {};
    char word[MAXLEN];
    
    while (scanf("%s", &word) != EOF)
    {
        int len = strlen(word);
        
        for (int i = 0; i < len - 2; i++) {
            //printf("%c%c%c\n", word[i], word[i + 1], word[i + 2]);
            table[word[i] - 'a'][word[i + 1] - 'a'][word[i + 2] - 'a']++;
        }
    }
    int first = 0, second = 0, third = 0;
    for (int q = 0; q < 3; q++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 26; k++) {
                    if (table[i][j][k] > table[first][second][third])
                    {
                        first = i;
                        second = j;
                        third = k;
                    }
                    
                }
            }
        }
        printf("%c%c%c\n", ('a' + first), ('a' + second), ('a' + third));
        
        table[first][second][third] = -1;
        first = second = third = 0;

    }
    
}   