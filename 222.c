#include <stdio.h>
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int main() {
    int bookshelf[8] = {};
    int cur;
    while (ReadInt(&cur)) {
        int find = 0;
        for (find = 0; find < 8; find++) {
            if (bookshelf[find] == cur)
            {
                break;
            }
        }
        if (find != 8) {
            for (int i = find; i < 7; i++) {
                bookshelf[i] = bookshelf[i + 1];
            }
            bookshelf[7] = cur;
        } else {
            for (int i = 0; i < 7; i++) {
                bookshelf[i] = bookshelf[i + 1];
            }
            bookshelf[7] = cur;
        }
        
    }
    for (int i = 0; i < 8; i++) {
        printf("%d ", bookshelf[i]);
    }
    // output your answer
    return 0;
}