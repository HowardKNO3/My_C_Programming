#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool is_vowel (char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main () {
    int ans = 0;
    char cur, before;
    while (true)
    {
        scanf("%c", &before);
        //printf("%c\n", before);
        if (!is_vowel(before) && isalpha(before)) {
            break;
        }
    }
    while (scanf("%c", &cur) != EOF)
    {
        if (is_vowel(cur) || !isalpha(cur)) {
            continue;
        } else if (cur > before) {
            ans++;
            //printf("%c %c %d\n", before, cur, ans);
        }
        before = cur;
        
    }
    printf("%d", ans);
    
}