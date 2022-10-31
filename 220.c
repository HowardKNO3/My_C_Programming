#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 200000

int main () {
    char s[MAXLEN] = {};
    char c;
    int size = 0;
    int cnt = 0;
    while (scanf("%c", &c) != EOF) {
        
        s[size] = c;
        //printf("%c %c\n", c, s[size]);
        size++;
        
    }
    for (int i = 0; i < MAXLEN; i++) {
        
        if (s[i] == '.') {
            if ((s[i + 1] == ' ' && s[i + 2] == ' ') || s[i + 1] == '\n' || s[i + 1] == '\0') {
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}