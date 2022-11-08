#include <stdio.h>
#include "set.h"
typedef unsigned long long Set;
#define ll unsigned long long
void init(Set *set) {
    *set = 0;
}

void add(Set *set, int i) {
    ll add = 1;
    for (int n = 0; n < i; n++) {
        add *= 2;
    }
    if ((*set & add) == 0) {
        (*set) = (*set) + add;
    }
    //printf("%lld\n", *set);
    return;
}

void has(Set set, int i) {
    ll check = 1;
    for (int n = 0; n < i; n++) {
        check *= 2;
    }
    if ((set & check) == 0) {
        printf("set does not have %d\n", i);
    } else {
        printf("set has %d\n", i);
    }
    return;
}

Set setUnion(Set a, Set b) {
    Set ret;
    init(&ret);
    ret = a | b;
    return ret;
}

Set setIntersect(Set a, Set b) {
    Set ret;
    init(&ret);
    ret = a & b;
    return ret;
}

Set setDifference(Set a, Set b) {
    Set ret;
    init(&ret);
    ret = a ^ b;
    return ret;
}
