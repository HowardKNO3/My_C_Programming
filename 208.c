#include <stdio.h>
#include <string.h>
int main () {
    int w, h;
    scanf("%d%d", &w, &h);
    char bit_char[2][2];
    scanf("%s%s", &bit_char[1], &bit_char[0]);
    int now_index = 0;
    unsigned int cur = 0;
    while (now_index < w * h)
    {
        //printf("%u", cur);
        scanf("%u", &cur);
        int bits[32] = {};
        for (int i = 0; i < 32; i++) {
            bits[31 - i] = cur % 2;
            cur /= 2;
        }
        /*
        for (int i = 0; i < 32; i++) {
            printf("%d ", bits[i]);
        }
        printf("\n");
        */
        for (int i = 0; i < 32 && (now_index + i) < (w * h); i++) {
            printf("%s", bit_char[bits[i]]);
            if ((now_index + i) % w == w - 1) {
                printf("\n");
            }
        }
        now_index += 32;
    }
    
}