#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAXM 2000
#define MAXLEN 600
char words[MAXM][MAXLEN];
int main () {
    char words[MAXM][MAXLEN];
    int width;
    scanf("%d", &width);
    int now_length = -1;
    int index = 0;
    
    while (scanf("%s", &words[index]) != EOF)
    {
        
        if (now_length + strlen(words[index]) + 1 <= width)
        {
            now_length++;
            now_length += strlen(words[index]);
            index++;
        } else {
            //printf("%d\n", now_length);
            if (index == 1) {
                printf("%s", words[index - 1]);
                for (int i = 0; i < width - now_length; i++) {
                    printf(" ");
                }
                
            } else {
                int occupied = now_length - (index - 1);
                int space = (width - occupied) / (index - 1);
                
                for (int i = 0; i < index - 1; i++) {
                    printf("%s", words[i]);
                    for (int j = 0; j < (i < (width - occupied) % (index - 1) ? space + 1 : space); j++) {
                        printf(" ");
                    }
                }
                printf("%s", words[index - 1]);
                
            }
            printf("\n");
            strcpy(words[0], words[index]);
            index = 0;
            now_length = -1;
            now_length++;
            now_length += strlen(words[0]);
            index++;
        }
    }
    if (index == 1) {
        printf("%s", words[index - 1]);
        for (int i = 0; i < width - now_length; i++) {
            printf(" ");
        }
        
    } else {
        int occupied = now_length - (index - 1);
        int space = (width - occupied) / (index - 1);
            
        for (int i = 0; i < index - 1; i++) {
            printf("%s", words[i]);
            for (int j = 0; j < (i < (width - occupied) % (index - 1) ? space + 1 : space); j++) {
                printf(" ");
            }
        }
        printf("%s", words[index - 1]);
                
    }
    printf("\n");
    
    
}