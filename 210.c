#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXN 50
#define MAXLEN 85
typedef struct user
{
    char last_name[MAXLEN];
    char first_name[MAXLEN];
    char ID[MAXLEN];
    int salary;
    int age;
} user;
bool is_condition_int (user* this_user, char* cond_1, char* op, int target) {
    if (cond_1[0] == 's') {
        if (strcmp(op, "==") == 0) {
            return (this_user->salary) == target;
        } else if (strcmp(op, ">") == 0) {
            return (this_user->salary) > target;
        } else {
            return (this_user->salary) < target;
        }
    } else {
        if (strcmp(op, "==") == 0) {
            return (this_user->age) == target;
        } else if (strcmp(op, ">") == 0) {
            return (this_user->age) > target;
        } else {
            return (this_user->age) < target;
        }
    }
}
bool is_condition (user* this_user, char* cond_1, char* op, char* cond_2) {
    if (cond_1[0] == 'l') {
        if (strcmp(op, "==") == 0) {
            return strcmp(cond_2, this_user->last_name) == 0;
        } else {
            return strcmp(cond_2, this_user->last_name) != 0;
        }
    }
    else if (cond_1[0] == 'f') {
        if (strcmp(op, "==") == 0) {
            return strcmp(cond_2, this_user->first_name) == 0;
        } else {
            return strcmp(cond_2, this_user->first_name) != 0;
        }
    }
    else {
        if (strcmp(op, "==") == 0) {
            return strcmp(cond_2, this_user->ID) == 0;
        } else {
            return strcmp(cond_2, this_user->ID) != 0;
        }
    }
}
void print_data (char commands[8][11], user* this_user, int cnt) {
    for (int i = 0; i < cnt; i++) {
        if (commands[i][0] == 'l') {
            printf("%s ", this_user->last_name);
        } else if (commands[i][0] == 'f') {
            printf("%s ", this_user->first_name);
        } else if (commands[i][0] == 'I') {
            printf("%s ", this_user->ID);
        } else if (commands[i][0] == 's') {
            printf("%d ", this_user->salary);
        } else {
            printf("%d ", this_user->age);
        }
    }
    printf("\n");
}
int main () {
    user users[MAXN] = {};
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        user this_user = {};
        scanf("%s%s%s%d%d", this_user.last_name, this_user.first_name, this_user.ID, &this_user.salary, &this_user.age);
        users[i] = this_user;
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        char select[11] = {};
        char commands[8][11] = {};
        scanf("%s", select);
        int cnt = 0;
        while (true) {
            scanf("%s", select);
            if (select[0] != 'w') {
                strcpy(commands[cnt], select);
                cnt++;
            } else {
                break;
            }
        }
        char cond_1[11] = {}, op[5] = {}, cond_2[11] = {};
        scanf("%s%s%s", cond_1, op, cond_2);
        int target = 0;
        if (cond_1[0] == 's' || cond_1[0] == 'a') {
            int len = strlen(cond_2);
            for (int i = 0; i < len; i++) {
                target *= 10;
                target += (cond_2[i] - '0');
            }
        }
        for (int i = 0; i < n; i++) {
            if (cond_1[0] == 's' || cond_1[0] == 'a') {
                if (is_condition_int(&users[i], cond_1, op, target)) {
                    print_data(commands, &users[i], cnt);
                }
            } else {
                if (is_condition(&users[i], cond_1, op, cond_2)) {
                    print_data(commands, &users[i], cnt);
                }
            }         
        }
    }
}