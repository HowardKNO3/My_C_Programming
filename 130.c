#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXLEN 85
int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s1[MAXLEN], s2[MAXLEN];
        scanf("%s%s", &s1, &s2);
        //printf("%s %s %d\n", s1, s2, strcmp(s1, s2));
        if (strcmp(s1, s2) == 0) {
            printf("yes\n");
        } else if (strlen(s1) == strlen(s2)) {
            bool similar = false;
            for (int i = 0; i < strlen(s1) - 1; i++) {
                char temp = s1[i];
                s1[i] = s1[i + 1];
                s1[i + 1] = temp;
                similar = similar || (strcmp(s1, s2) == 0);
                //printf("%s\n", s1);
                temp = s1[i];
                s1[i] = s1[i + 1];
                s1[i + 1] = temp;
                //printf("%s\n\n", s1);
            }
            if (similar) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else if (strlen(s1) == strlen(s2) + 1 || strlen(s2) == strlen(s1) + 1) {
            bool similar = true;
            bool deleted = false;
            int ptr_1 = 0;
            int ptr_2 = 0;
            while (ptr_1 != strlen(s1) && ptr_2 != strlen(s2)) {
                if (s1[ptr_1] != s2[ptr_2]) {
                    if (deleted) {
                        similar = false;
                    } else {
                        deleted = true;
                        (strlen(s1) > strlen(s2)) ? ptr_2-- : ptr_1--;
                    }
                }
                ptr_1++;
                ptr_2++;
            }
            if (similar) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else {
            printf("no\n");
        }
        
    }
}