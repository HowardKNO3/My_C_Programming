#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sumOfIntegers.h"
#define MAXLEN 300

void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks) {
    int index = 0; 
    if (ptrArray[0] == NULL && ptrArray[1] == NULL) {
        return;
    }
    int *seen[MAXLEN] = {};
    while (ptrArray[index] != NULL)
    {
        int now_seen = 0;
        for (int i = 0; i < MAXLEN; i++) {
            seen[i] = NULL;
        }
        while (ptrArray[index] != NULL)
        {
            
            bool visited = false;
            for (int i = 0; i < now_seen; i++) {
                visited = visited || (ptrArray[index] == seen[i]);
            }
            //printf("%d %d\n", *ptrArray[index], visited);
            if (!visited) {
                answer[(*numberOfBlocks)] += *ptrArray[index];
                seen[now_seen] = ptrArray[index];
                now_seen++;
            }            
            index++;
             //printf("%d\n", answer[(*numberOfBlocks)]);
        }
        (*numberOfBlocks)++;
        index++;
    }
    return;
}