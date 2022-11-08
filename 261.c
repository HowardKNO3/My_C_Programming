#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLEN 10

int to_int(int indices[26], char s[MAXLEN], int sol[MAXLEN]) {
    int ans = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        ans *= 10;
        if (isupper(s[i])) {
            ans += sol[indices[(s[i] - 'A')]];
        } else {
            ans += s[i] - '0';
        }
    }
    return ans;
}

void solve(int indices[26], char num_1[MAXLEN], char num_2[MAXLEN], char ans[MAXLEN], int sol[MAXLEN], int index, int types) {
    if (index == types) {
        if (to_int(indices, num_1, sol) * to_int(indices, num_2, sol) == to_int(indices, ans, sol)) {
            printf("%d x %d = %d\n", to_int(indices, num_1, sol), to_int(indices, num_2, sol), to_int(indices, ans, sol));
            exit(0);
        }
    } else {
        for (int i = 1; i < 10; i++) {
            sol[index] = i;
            solve(indices, num_1, num_2, ans, sol, index + 1, types);
            sol[index] = 0;
        }
    }
    
    
}

int main () {
    char num_1[MAXLEN] = {};
    char num_2[MAXLEN] = {};
    char ans[MAXLEN] = {};
    scanf("%s %s %s", num_1, num_2, ans);
    int indices[26] = {};
    int sol[MAXLEN] = {};
    for (int i = 0; i < 26; i++) {
        indices[i] = -1;
    }
    int types = 0;
    for (int i = 0; i < strlen(num_1); i++) {
        if (isupper(num_1[i]) && indices[num_1[i] - 'A'] == -1) {
            indices[num_1[i] - 'A'] = types;
            types++;
        }
    }
    for (int i = 0; i < strlen(num_2); i++) {
        if (isupper(num_2[i]) && indices[num_2[i] - 'A'] == -1) {
            indices[num_2[i] - 'A'] = types;
            types++;
        }
    }
    for (int i = 0; i < strlen(ans); i++) {
        if (isupper(ans[i]) && indices[ans[i] - 'A'] == -1) {
            indices[ans[i] - 'A'] = types;
            types++;
        }
    }
    
    solve(indices, num_1, num_2, ans, sol, 0, types);
}