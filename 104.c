#include <stdio.h>
#include <stdbool.h>




bool ok (int a, int b, int c, int materials[3][3]) {
    if (a < 0 || b < 0 || c < 0) return false;
    if (a == 0 && b == 0 && c == 0) return true;
    return ok(a - materials[0][0], b - materials[0][1], c - materials[0][2], materials) ||
    ok(a - materials[1][0], b - materials[1][1], c - materials[1][2], materials) ||
    ok(a - materials[2][0], b - materials[2][1], c - materials[2][2], materials);
}

void work (int t, int materials[3][3]) {
    if (t == 0) {
        return;
    }
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (ok(a, b, c, materials)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    work(t - 1, materials);
}

void input_materials (int index, int materials[3][3]) {
    if (index == 9) {
        return;
    }
    scanf("%d", &materials[index / 3][index % 3]);
    input_materials(index + 1, materials);
}

int main () {
    int materials[3][3] = {};
    input_materials(0, materials);
    int t;
    scanf("%d", &t);
    work(t, materials);
}