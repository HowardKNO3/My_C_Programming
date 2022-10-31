#include <stdio.h>
#include <string.h>
#define MAXLEN 128

int min (int a, int b) {
    return (a < b) ? a : b;
}

int main () {
    char ans[MAXLEN] = "";
    scanf("%s", &ans);
    char cur[MAXLEN] = "";
    
    while (scanf("%s", &cur) != EOF)
    {
        int len1 = strlen(ans);
        int len2 = strlen(cur);
        for (int i = min(len1, len2); i >= 0; i--) {
            
            if (strncmp(ans[len1 - i], cur[0], i) == 0) {
                
                for (int j = 0; j < strlen(cur); j++) {
                    //printf("%d %d\n", i, j);
                    ans[len1 - i + j] = cur[j]; 
                }
                break;
            }
            
        }
        
        
    }
    printf("%s\n", ans);
}