#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXLEN 100

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

 
int main(int argc, char const *argv[])
{
    int a, b, c, d, e, f, g, h, number = 0;
    int *numberOfBlocks = &number;
    const int *ptrArray[32];
    int answer[32] = {0};
    scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
    ptrArray[0] = &b;
    ptrArray[1] = &a;
    ptrArray[2] = &a;
    ptrArray[3] = &b;
    ptrArray[4] = &c;
    ptrArray[5] = &f;
    ptrArray[6] = &e;
    ptrArray[7] = &a;
    ptrArray[8] = &b;
    ptrArray[9] = &b;
    ptrArray[10] = NULL;
    ptrArray[11] = &d;
    ptrArray[12] = &g;
    ptrArray[13] = &e;
    ptrArray[14] = &b;
    ptrArray[15] = &f;
    ptrArray[16] = &c;
    ptrArray[17] = &f;
    ptrArray[18] = &c;
    ptrArray[19] = &a;
    ptrArray[20] = &a;
    ptrArray[21] = &e;
    ptrArray[22] = &d;
    ptrArray[23] = NULL;
    ptrArray[24] = &a;
    ptrArray[25] = &c;
    ptrArray[26] = &g;
    ptrArray[27] = &c;
    ptrArray[28] = &c;
    ptrArray[29] = &e;
    ptrArray[30] = NULL;
    ptrArray[31] = NULL;
    sumOfIntegers(ptrArray, answer, numberOfBlocks);
    for(int index = 0; index < *numberOfBlocks; index++) {
        printf("%d ", answer[index]);
    }
    return 0;
}