#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXN 105
#define MAXLEN 10
#define MAXLINES 1005
int get_variable_index (char variable_names[MAXN][MAXLEN], char variable[MAXLEN]) {
    int index = 0;
    while (strcmp(variable_names[index], "") != 0)
    {
        
        if (strcmp(variable_names[index], variable) == 0) {
            return index;
        }
        index++;
    }
    return -1;
    
}

int get_cmp_op_index (char op[MAXLEN]) {
    if (strcmp(op, "==") == 0) {
        return 0;
    }
    if (strcmp(op, "!=") == 0) {
        return 1;
    }
    if (strcmp(op, ">") == 0) {
        return 2;
    }
    if (strcmp(op, "<") == 0) {
        return 3;
    }
    if (strcmp(op, ">=") == 0) {
        return 4;
    }
    if (strcmp(op, "<=") == 0) {
        return 5;
    }

}

int get_calc_op_index (char op[MAXLEN]) {
    if (strcmp(op, "+") == 0) {
        return 0;
    }
    if (strcmp(op, "-") == 0) {
        return 1;
    }
    if (strcmp(op, "*") == 0) {
        return 2;
    }
    if (strcmp(op, "/") == 0) {
        return 3;
    }
    if (strcmp(op, "%") == 0) {
        return 4;
    }
    

}

bool check (int v1, int op, int v2) {
    if (op == 0) {
        return v1 == v2;
    }
    if (op == 1) {
        return v1 != v2;
    }
    if (op == 2) {
        return v1 > v2;
    }
    if (op == 3) {
        return v1 < v2;
    }
    if (op == 4) {
        return v1 >= v2;
    }
    if (op == 5) {
        return v1 <= v2;
    }
}
int calculate (int v1, int op, int v2) {
    if (op == 0) {
        return v1 + v2;
    }
    if (op == 1) {
        return v1 - v2;
    }
    if (op == 2) {
        return v1 * v2;
    }
    if (op == 3) {
        return v1 / v2;
    }
    if (op == 4) {
        return v1 % v2;
    }
    
} 
int main () {
    char variable_names[MAXN][MAXLEN] = {};
    int variable_values[MAXN] = {};
    int variable_cnt = 0;
    while (true)
    {
        char v_name[MAXLEN] = {};
        scanf("%s", &v_name);
        //printf("%s\n", v_name);
        if (strcmp(v_name, "END") == 0) {
            break;
        } else {
            char op[MAXLEN];
            int value;
            scanf("%s%d", &op, &value);
            strcpy(variable_names[variable_cnt], v_name);
            variable_values[variable_cnt] = value;
            variable_cnt++;
        } 
    }
    //printf("ok");
    int lines[MAXLINES][5] = {};
    int lines_cnt = 1;
    char first_word[MAXLEN] = {};
    while (scanf("%s", &first_word) != EOF)
    {
        //printf("%s\n", first_word);
        if (strcmp(first_word, "IF") == 0) {
            lines[lines_cnt][0] = 0;
            char v1[MAXLEN], op[MAXLEN], v2[MAXLEN], GOTO[MAXLEN];
            int dest;
            scanf("%s %s %s %s %d", &v1, &op, &v2, &GOTO, &dest);
            lines[lines_cnt][1] = get_variable_index(variable_names, v1);
            lines[lines_cnt][2] = get_cmp_op_index(op);
            lines[lines_cnt][3] = get_variable_index(variable_names, v2);
            lines[lines_cnt][4] = dest;
            //printf("%d %d %d %d %d\n", lines[lines_cnt][0], lines[lines_cnt][1], lines[lines_cnt][2], lines[lines_cnt][3], lines[lines_cnt][4]);
        } else if (strcmp(first_word, "GOTO") == 0) {
            int dest;
            scanf("%d", &dest);
            lines[lines_cnt][0] = 1;
            lines[lines_cnt][1] = dest;
        } else if (strcmp(first_word, "PRINT") == 0) {
            lines[lines_cnt][0] = 2;
            char v[MAXLEN] = {};
            scanf("%s", &v);
            lines[lines_cnt][1] = get_variable_index(variable_names, v);
        } else if (strcmp(first_word, "STOP") == 0){
            lines[lines_cnt][0] = 3;
        } else {
            lines[lines_cnt][0] = 4;
            char equal[MAXLEN];
            char v1[MAXLEN], op[MAXLEN], v2[MAXLEN];
            int dest;
            scanf("%s %s %s %s", &equal ,&v1, &op, &v2);
            //printf("%s %s %s %s %d\n", v1, op, v2, GOTO, dest);
            lines[lines_cnt][1] = get_variable_index(variable_names, first_word);
            lines[lines_cnt][2] = get_variable_index(variable_names, v1);
            lines[lines_cnt][3] = get_calc_op_index(op);
            lines[lines_cnt][4] = get_variable_index(variable_names, v2);
        }
        lines_cnt++;
        /*
        for (int i = 0; i < lines_cnt; i++) {
            for (int j = 0; j < 5; j++) {
                printf("%d ", lines[i][j]);
            }
            printf("\n");
        }
        printf("%d\n", lines_cnt);
        */
    }
    int now_line = 1;
    while (true) {
        //printf("%d\n", now_line);
        if (lines[now_line][0] == 0) {
            if (check(variable_values[lines[now_line][1]], lines[now_line][2], variable_values[lines[now_line][3]])) {
                now_line = lines[now_line][4];
            } else {
                now_line++;
            }
        } else if (lines[now_line][0] == 1) {
            now_line = lines[now_line][1];
        } else if (lines[now_line][0] == 2) {
            printf("%d\n", variable_values[lines[now_line][1]]);
            now_line++;
        } else if (lines[now_line][0] == 3) {
            break;
        } else {
            variable_values[lines[now_line][1]] = calculate(variable_values[lines[now_line][2]], lines[now_line][3], variable_values[lines[now_line][4]]);
            now_line++;
        }
    }
    
}