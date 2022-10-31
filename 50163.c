#include <stdio.h>
#include <stdbool.h>

int main () {
    int n;
    scanf("%d", &n);
    int seats[n * 100];
    for (int i = 0; i < n * 100; i++) {
        seats[i] = 1;
    }
    int single_index = 0;
    int double_index = 0;
    int cur = 0;
    while (scanf("%d", &cur) != EOF)
    {
        if (cur == 1) {
            while (seats[single_index] != 1)
            {
                single_index++;
            }
            seats[single_index] = 0;
            printf("%d %d %d\n", (1 + single_index / 100), (1 + (single_index % 100) / 5), (1 + single_index % 5));
        } if (cur == 2) {
            bool available = (double_index < n * 100 - 1);
            if (available) {
                
                while (true)
                {
                    bool b1 = (seats[double_index] == 1) && (seats[double_index + 1] == 1);
                    bool b2 = (double_index % 5 != 2) && (double_index % 5 != 4);
                    
                    available = (double_index < n * 100 - 1);
                    if (!available || (b1 && b2)) {
                        break;
                    } else {
                        double_index++;
                    }
                }
                //printf("%d\n", double_index);
                if (available) {
                    printf("%d %d %d %d %d %d\n", (1 + double_index / 100), (1 + (double_index % 100) / 5), (1 + double_index % 5), (1 + double_index / 100), (1 + (double_index % 100) / 5), (2 + double_index % 5));
                    seats[double_index] = 0;
                    seats[double_index + 1] = 0;
                }
            }
            if (!available) {
                for (int i = 0; i < 2; i++) {
                    while (seats[single_index] != 1) {
                        single_index++;
                    }
                    seats[single_index] = 0;
                    printf("%d %d %d", (1 + single_index / 100), (1 + (single_index % 100) / 5), (1 + single_index % 5));
                    if (i == 0) {
                        printf(" ");
                    } else {
                        printf("\n");
                    }
                }
                
            }
        }
    }
    
}