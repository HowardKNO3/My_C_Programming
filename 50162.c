#include <stdio.h>

int main () {
    int players[3][5000] = {0};
    int front[3] = {0};
    int rear[3] = {0};
    int cur;
    while (scanf("%d", &cur) != EOF)
    {
        int type = cur % 3;
        players[type][rear[type] % 5000] = cur;
        rear[type]++;
        if ((rear[0] - front[0]) >= 3 && (rear[1] - front[1]) >= 1 && (rear[2] - front[2]) >= 1) {
            printf("%d ", players[0][front[0] % 5000]);
            printf("%d ", players[0][(front[0] + 1) % 5000]);
            printf("%d ", players[0][(front[0] + 2) % 5000]);
            printf("%d ", players[1][front[1] % 5000]);
            printf("%d\n", players[2][front[2] % 5000]);
            front[0] += 3;
            front[1]++;
            front[2]++;
        }
    }
    
    
}