#include <stdio.h>
#define MAXLEN 1000

int main () {
    while (1)
    {
        char s[MAXLEN] = {};
        scanf("%s", s);
        if (s[0] == '-' && s[1] == '1') {
            break;
        }
        int cnt = 0;
        while (1) {
            if (s[cnt] >= '0' && s[cnt] <= '9' && cnt < MAXLEN) {
                cnt++;
            } else {
                break;
            }
        }
        int total[2] = {0, 0};
        for (int i = 0; i < cnt; i++) {
            total[i % 2] += (s[i] - '0');
        }
        if ((s[cnt - 1] - '0') % 2 == 0) {
            printf("yes ");
        } else {
            printf("no ");
        }
    
        if ((total[0] + total[1]) % 3 == 0) {
            printf("yes ");
        } else {
            printf("no ");
        }
        if ((s[cnt - 1] - '0') % 5 == 0) {
            printf("yes ");
        } else {
            printf("no ");
        }
        if ((total[0] - total[1]) % 11 == 0) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    
    
}