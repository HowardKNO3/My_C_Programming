#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAXHASH 1200
#define MAXDEPTH 5
#define MAXLEN 25


int hash_function (char* s) {
    int sum = 0;
    int index = 0;
    while (s[index] != '\0') {
        sum += s[index];
        index++;
    }
    return sum % 1000;
}

bool is_valid(char* s) {
    int index = 0;
    while (s[index] != '\0') {
        if (index == 0 && !isalpha(s[index]) && s[index] != '_') {
            return false;
        } else if (!isalnum(s[index]) && s[index] != '_') {
            return false;
        }
        index++;
    }
    return true;
}

int main () {
    char variable_name[MAXLEN] = {};
    char string_hash_table[MAXHASH][MAXDEPTH][MAXLEN] = {};
    int value_hash_table[MAXHASH][MAXDEPTH] = {};

    while (scanf("%s", variable_name) != EOF) {
        if (!is_valid(variable_name))
        {
            continue;
        }
        
        /*
        if (is_valid(variable_name)) {
            printf("%s\n", variable_name);
        }
        */
        int hash = hash_function(variable_name);
        //printf("%d\n", hash);
        int index = 0;
        while (index < MAXDEPTH) {
            if (strcmp(string_hash_table[hash][index], variable_name) == 0) {
                break;
            }
            index++;
        }
        if (index == MAXDEPTH){
            index = 0;
            while (index < MAXDEPTH) {
                if (strcmp(string_hash_table[hash][index], "") == 0) break;
                index++;
            }
            strcpy(string_hash_table[hash][index], variable_name);
        }
        value_hash_table[hash][index]++;
        if (value_hash_table[hash][index] != 0) {
            printf("%s %d\n", variable_name, value_hash_table[hash][index]);
        }
    }
}
