#include <stdio.h>
#define ll unsigned long long
typedef struct Set
{
    ll bits;
} Set;

void init(Set *set) {
    (set -> bits) = 0;
}

void add(Set *set, int i) {
    ll add = 1;
    for (int n = 0; n < i; n++) {
        add *= 2;
    }
    if (((set -> bits) & add) == 0) {
        (set -> bits) = (set -> bits) + add;
    }
    printf("%lld\n", set -> bits);
    return;
}

void has(Set set, int i) {
    ll check = 1;
    for (int n = 0; n < i; n++) {
        check *= 2;
    }
    if ((set.bits & check) == 0) {
        printf("set does not have %d\n", i);
    } else {
        printf("set has %d\n", i);
    }
    return;
}

Set setUnion(Set a, Set b) {
    Set ret;
    init(&ret);
    ret.bits = a.bits | b.bits;
    return ret;
}

Set setIntersect(Set a, Set b) {
    Set ret;
    init(&ret);
    ret.bits = a.bits & b.bits;
    return ret;
}

Set setDifference(Set a, Set b) {
    Set ret;
    init(&ret);
    ret.bits = a.bits ^ b.bits;
    return ret;
}

int main()
{
    Set a, b, c;
    
    init(&a);
    add(&a, 3);
    add(&a, 5);
    add(&a, 2);
    //printf("%lld\n", a.bits);
    init(&b);
    add(&b, 3);
    add(&b, 7);
    add(&b, 9);
    //printf("%lld\n", b.bits);
    
    c = setUnion(a, b);
    //printf("%lld\n", c.bits);
    has(c, 2);
    has(c, 3);
    has(c, 5);
    has(c, 7);
    has(c, 9);
    
    c = setIntersect(a, b);
    has(c, 2);
    has(c, 3);
    has(c, 5);
    has(c, 7);
    has(c, 9);
    
    c = setDifference(a, b);
    has(c, 2);
    has(c, 3);
    has(c, 5);
    has(c, 7);
    has(c, 9);
    
    return 0;
}