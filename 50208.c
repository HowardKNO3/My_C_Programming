#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 500

int main () {
    char this_word[MAXLEN] = {};
    char cur = ' ';
    int index = 0;
    int ans = 0;
    while (scanf("%c", &cur) != EOF)
    {
        
        //printf("%c\n", cur);
        //printf("%s\n", this_word);
        if (cur == '?') {
            ans++;
            memset(this_word, 0, strlen(this_word));
            index = 0;
        } else if (isspace(cur) || cur == '(') {
            if (strcmp(this_word, "case") == 0 || strcmp(this_word, "for") == 0 || strcmp(this_word, "while") == 0 || strcmp(this_word, "if") == 0) {
                ans++;
            } 
            memset(this_word, 0, strlen(this_word));
            index = 0;
        } else if (cur == '\n' || cur == ';' || cur == ')' || cur == ',') {
            memset(this_word, 0, strlen(this_word));
            index = 0;
        } else {
            this_word[index] = cur;
            index++;
        }
        
    }
    printf("%d", ans);
}