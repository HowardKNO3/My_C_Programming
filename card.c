#include "card.h"
#include <stdio.h>
int get_size (int *deck[]) {
    int cnt = 0;
    while (deck[cnt] != NULL) {
        cnt++;
    }
    return cnt;
}

void shuffle(int *deck[]) {
    int size = get_size(deck);
    int *new_deck[10000];
    for (int i = 0; i < size / 2; i++) {
        //printf("%d\n", *deck[i]);
        new_deck[2 * i] = deck[i];
        //printf("%d\n", *deck[(size + 1) / 2 + i]);
        new_deck[2 * i + 1] = deck[(size + 1) / 2 + i];
    }
    if (size % 2 != 0) {
        new_deck[size - 1] = deck[size / 2];
    }
    for (int i = 0; i < size; i++) {
        deck[i] = new_deck[i];
    }
}

void print(int *deck[]) {
    int size = get_size(deck);
    for (int i = 0; i < size; i++) {
        printf("%d ", *deck[i]);
    }
}