#include <stdio.h>
#include <ctype.h>
#define MAXLEN 100
int main () {
    char s[MAXLEN];
    int cnt = 0;
    char c;
    while (scanf("%c", &c) != EOF)
    {
        s[cnt] = c;
        cnt++;
    }
    int left = 0;
    while (1)
    {
        if (isspace(s[left])) {
            left++;
        } else {
            break;
        }
    }
    int right = cnt - 1;
    while (1)
    {
        if (isspace(s[right])) {
            right--;
        } else {
            break;
        }
    }
    for (int i = left; i <= right; i++) {
        printf("%c", s[i]);
    }
    
}