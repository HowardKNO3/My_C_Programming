#include "max.h"


int max (int *iptr[], int n) {
    int ret = -1000000000;
    for (int i = 0; i < n; i++) {
        if (ret < *iptr[i]) {
            ret = *iptr[i];
        }
    }
    return ret;
}

