#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXLEN 128

bool skip (char cur[MAXLEN]) {
    return strcmp(cur, "of") == 0 || strcmp(cur, "and") == 0 || strcmp(cur, "the") == 0 || strcmp(cur, "at") == 0
    || strcmp(cur, "of.") == 0 || strcmp(cur, "and.") == 0 || strcmp(cur, "the.") == 0 || strcmp(cur, "at.") == 0;
}

int main () {
    char cur[MAXLEN];
    while (scanf("%s", &cur) != EOF)
    {
        if (!skip(cur)) {
            printf("%c", (cur[0] - 32));
        }
        
        if (cur[strlen(cur) - 1] == '.') {
            printf("\n");
        }
    }
    
}