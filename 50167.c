#include <stdio.h>
#include <stdbool.h>
#define MAXN 20000

double get_index(int itemID[], int this_id) {
    int ret = 0;
    while (itemID[ret] != this_id && itemID[ret] == 0)
    {
        ret++;
    }
    return ret;
}

double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[]) {
    bool is_on_sale[MAXN + 1] = {};
    for (int i = 0; i < MAXN && itemID[i] != 0; i++) {
        for (int j = 0; j < MAXN && onSaleItemID[j] != 0; j++) {
            if (itemID[i] == onSaleItemID[j]) {
                is_on_sale[j] == true;
                break;
            }
        }
    }
    double ret = 0;
    int cnt = 0;
    while (onSaleItemID[cnt] != 0)
    {
        int index = get_index(itemID, onSaleItemID[cnt]);
        ret += price[index] * orderQuantity[cnt];
        if (is_on_sale[index]) {
            ret *= 0.8;
        }
    }
    if (ret < 490) ret += 80;
    return ret;
    


}

int main(int argc, char const *argv[])
{
    int itemID[MAXN+1], orderItemID[MAXN+1], orderQuantity[MAXN+1], onSaleItemID[MAXN+1];
    double price[MAXN+1];
    int itemCnt, orderCnt, onSaleCnt;
    scanf("%d%d%d", &itemCnt, &orderCnt, &onSaleCnt);
    
    for(int i = 0; i < itemCnt; i++) {
        scanf("%d%lf", &itemID[i], &price[i]);
    }
    itemID[itemCnt] = 0, price[itemCnt] = 0;
    
    for(int i = 0; i < orderCnt; i++) {
        scanf("%d%d", &orderItemID[i], &orderQuantity[i]);
    }
    orderItemID[orderCnt] = 0, orderQuantity[orderCnt] = 0;
    
    for(int i = 0; i < onSaleCnt; i++) {
        scanf("%d", &onSaleItemID[i]);
    }
    onSaleItemID[onSaleCnt] = 0;
    
    double pay = payment(itemID, price, orderItemID, orderQuantity, onSaleItemID);
    printf("%.1lf\n", pay);
    
    return 0;
}