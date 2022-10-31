#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define numPtrArray 10
#define MAXLEN 400000

void splitAndMap(char*** ptr, char* str) {
    int len[numPtrArray + 1] = {};
    int size[numPtrArray + 1] = {};
    
    const char s[2] = "*";
    char *token;
    token = strtok(str, s);
    while (token != NULL)
    {
        int min_index = 0;
        for (int i = 0; ptr[i] != NULL; i++) {
            if (len[i] < len[min_index]) {
                min_index = i;
            }
        }
        if (strcmp(token, "") == 0) {
            continue;
        }
        ptr[min_index][size[min_index]] = token;
        size[min_index]++;
        len[min_index] += strlen(token);
        //printf("%d %d\n", min_index, size[min_index]);
        token = strtok(NULL, s);
    }
    //printf("\n");
    
    
    
}