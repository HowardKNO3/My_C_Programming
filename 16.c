#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n], arr_odd[n], arr_even[n];
    int odd_index = 0, even_index = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &(arr[i]));
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            arr_even[even_index] = arr[i];
            even_index++;
        }
        else {
            arr_odd[odd_index] = arr[i];
            odd_index++;
        }
    }
    for (int i = 0; i < odd_index - 1; i++) {
        printf("%d ", arr_odd[i]);
    }
    printf("%d\n", arr_odd[odd_index - 1]);

    for (int i = 0; i < even_index - 1; i++) {
        printf("%d ", arr_even[i]);
    }
    printf("%d", arr_even[even_index - 1]);
}