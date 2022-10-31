#include <stdio.h>
#define MAXLEN 100

int main () {
    char s[MAXLEN] = {};
    int cnt[26] = {};
    scanf("%s", &s);
    for (int i = 0; i < MAXLEN; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            cnt[s[i] - 'A']++;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            cnt[s[i] - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        printf("%d\n", cnt[i]);
    }
    
}