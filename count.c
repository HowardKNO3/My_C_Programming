#include <stdio.h>

#define MAX_SIZE_PTRARRAY 512
#define MAX_NUM_PTR 512
#define MAX_NUM_INTVAR 512
#define MAXSIZE 530
void count(int **p[]) {
    int now_size = 0;
    int *num_ptr[MAXSIZE] = {};
    int cnt[MAXSIZE] = {};
    for (int i = 0; p[i] != NULL; i++) {
        int index = 0;
        for (index = 0; index < now_size; index++) {
            if (*p[i] == num_ptr[index]) {
                break;
            }
        }
        if (index == now_size) {
            num_ptr[index] = *p[i];
            now_size++;
        }
        cnt[index]++;
    }
    for (int i = now_size - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            if (cnt[j] > cnt[j + 1] || (cnt[j] == cnt[j + 1] && *(num_ptr[j]) > *(num_ptr[j + 1]))) {
                int temp_cnt = cnt[j];
                int *temp_ptr = num_ptr[j];
                cnt[j] = cnt[j + 1];
                num_ptr[j] = num_ptr[j + 1];
                cnt[j + 1] = temp_cnt;
                num_ptr[j + 1] = temp_ptr;
            }
        }
    }
    for (int i = 0; i < now_size; i++) {
        printf("%d %d\n", *(num_ptr[i]), cnt[i]);
    }
    
} 