#include <stdio.h>
#include <stdbool.h>

bool inside (int row, int col, int cmd) {
    int dir[6][2] = {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}};
    row += dir[cmd][0];
    col += dir[cmd][1];
    if (row == 0) {
        return (col <= 9 && col >= 0);
    } else if (row == 1) {
        return (col <= 8 && col >= 0);
    } else if (row == 2) {
        return (col <= 6 && col >= 0);
    } else {
        return false;
    }
}

int main () {
    char alphabet[3][10] = {{'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'}, {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\0'}, {'z', 'x', 'c', 'v', 'b', 'n', 'm', '\0', '\0', '\0'}};
    int row = 0, col = 0;
    int dir[6][2] = {{0, 1}, {-1, 1}, {-1, 0}, {0, -1}, {1, -1}, {1, 0}};
    char cur;
    scanf("%c", &cur);
    bool found = false;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 10; col++) {
            //printf("%d %d %c\n", row, col, alphabet[row][col]);
            if (cur == alphabet[row][col]) {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    printf("%c\n", cur);
    int cmd;
    while (scanf("%d", &cmd) != EOF)
    {
        //printf("%d %d\n", row, col);
        if (inside(row, col, cmd)) {
            row += dir[cmd][0];
            col += dir[cmd][1];
            printf("%c\n", alphabet[row][col]);
        }
        
    }
    
}