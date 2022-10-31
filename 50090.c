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

int main(){
    
    
    int **ptrArray[MAX_SIZE_PTRARRAY] = {};
    int  *intPtr[MAX_NUM_PTR];
    int   intVar[MAX_NUM_INTVAR];
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    for (int i = 0; i < n1; i++) {
        int index;
        scanf("%d", &index);
        ptrArray[i] = &intPtr[index];
    }
    for (int i = 0; i < n2; i++) {
        int index;
        scanf("%d", &index);
        intPtr[i] = &intVar[index];
    }
    for (int i = 0; i < n3; i++) {
        scanf("%d", &intVar[i]);
    }
    /*
    intVar[0] = 3;
    intVar[1] = 8;
    intVar[2] = 6;
    intVar[3] = 9;
    ptrArray[0] = &intPtr[3];
    ptrArray[1] = &intPtr[2];
    ptrArray[2] = &intPtr[1];
    ptrArray[3] = &intPtr[0];
    ptrArray[4] = NULL;
    intPtr[0] = &intVar[3];
    intPtr[1] = &intVar[2];
    intPtr[2] = &intVar[1];
    intPtr[3] = &intVar[0];
    */
    count(ptrArray);
    
    return 0;
}