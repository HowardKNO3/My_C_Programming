#define MAXN 20000
#include "payment.h"
#include <stdio.h>
#include <stdbool.h>
#define MAXN 20000

double get_index(int itemID[], int this_id) {
    int ret = 0;
    
    while (itemID[ret] != this_id && itemID[ret] != 0)
    {
        ret++;
    }
    //printf("%d\n", ret);
    return ret;
}

double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[]) {
    bool is_on_sale[MAXN + 1] = {};
    for (int i = 0; i < MAXN && itemID[i] != 0; i++) {
        for (int j = 0; j < MAXN && onSaleItemID[j] != 0; j++) {
            //printf("%d %d\n", i, j);
            if (itemID[i] == onSaleItemID[j]) {
                //printf("%d\n", i);
                is_on_sale[i] = true;
                break;
            }
        }
    }
    /*
    for (int i = 0; i < MAXN && itemID[i] != 0; i++) {
        printf("%d ", is_on_sale[i]);
    }
    */
    double ret = 0;
    int cnt = 0;
    while (orderItemID[cnt] != 0)
    {
        int index = get_index(itemID, orderItemID[cnt]);
        double this_price = price[index] * orderQuantity[cnt];
        
        if (is_on_sale[index]) {
            this_price *= 0.8;
        }
        ret += this_price;
        //printf("%d %lf %lf\n", index, this_price, ret);
        cnt++;
    }
    if (ret < 490) ret += 80;
    return ret;
    


}