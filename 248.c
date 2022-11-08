#include <stdio.h>
#include <stdbool.h>



bool solve (int field[11][11], int mines[11][11], int i, int j) {
    if (i == 10) {
        bool ok = true;
        for (int i = 1; i <= 9 && ok; i++) {
            for (int j = 1; j <= 9 && ok; j++) {
                ok = ok && field[i][j] == 0;
            }
        }
        return ok;
    }
    bool ret = false;
    if (field[i - 1][j - 1] > 1) {
        return false;
    } else if (field[i - 1][j - 1] == 0) {
        ret = solve(field, mines, (j + 1 > 9) ? i + 1 : i, (j + 1 > 9) ? 1 : j + 1);
    }
    if (ret) {
        return true;
    }
    bool check = true;
    for (int x = i - 1; x <= i + 1 && check; x++) {
        for (int y = j - 1; y <= j + 1 && check; y++) {
            if (!(x >= 1 && x <= 9) || !(y >= 1 && y <= 9)) continue;
            if (field[i][j] < 1) {
                check = false;
            }
        }
    }
    
    if (check) {
        for (int x = i - 1; x <= i + 1 && check; x++) {
            for (int y = j - 1; y <= j + 1 && check; y++) {
                if (!(x >= 1 && x <= 9) || !(y >= 1 && y <= 9)) continue;
                field[x][y]--;
            }
        }
        mines[i][j] = 1;
        if (solve(field, mines, (j + 1 > 9) ? i + 1 : i, (j + 1 > 9) ? 1 : j + 1)) {
            return true;
        } else {
            mines[i][j] = 0;
            for (int x = i - 1; x <= i + 1 && check; x++) {
                for (int y = j - 1; y <= j + 1 && check; y++) {
                    if (!(x >= 1 && x <= 9) || !(y >= 1 && y <= 9)) continue;
                    field[x][y]++;
                }
            }
        }
    }
    return false;
}

int main () {
    int field[11][11] = {};
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            scanf("%d", &field[i][j]);
        }
    }
    int mines[11][11] = {};
    if (solve(field, mines, 1, 1)) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 8; j++) {
                printf("%d ", mines[i][j]);
            }
            printf("%d", mines[i][9]);
            printf("\n");
        }
    } else {
        printf("no solution\n");
    }
}