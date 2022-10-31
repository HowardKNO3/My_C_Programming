#include <stdio.h>
#include <stdlib.h>

int max (int a, int b) {
    return (a > b) ? a : b;
}
int min (int a, int b) {
    return (a < b) ? a : b;
}

int calculate_damage (int base_damage, int extra_damage, int cooldown, int last_use, int now_round) {
    if (last_use == -1) {
        return base_damage + extra_damage * (max(0, now_round - cooldown));
    } else {
        return (now_round - last_use >= cooldown) ? (base_damage + extra_damage * (now_round - last_use - cooldown)) : -1;
    }
}

int main () {
    int base_damage[4] = {0};
    int extra_damage[3] = {0};
    int cooldown[3] = {0};
    int round, max_hp, hp, regen;
    scanf("%d%d%d", &round, &max_hp, &regen);
    hp = max_hp;
    for (int i = 0; i < 3; i++) {
        scanf("%d%d%d", &base_damage[i], &extra_damage[i], &cooldown[i]);
    }
    scanf("%d", &base_damage[3]);
    int last_use[3] = {-1, -1, -1};
    for (int now_round = 0; now_round < round; now_round++) {
        int choose_skill = 3;
        int damage = base_damage[3];
        for (int i = 0; i < 3; i++) {
            int this_damage = calculate_damage(base_damage[i], extra_damage[i], cooldown[i], last_use[i], now_round);
            if (this_damage > damage) {
                choose_skill = i;
                damage = this_damage;
            }
        }
        if (choose_skill != 3) {
            last_use[choose_skill] = now_round;
        }
        hp -= damage;
        printf("%d", hp);
        
        
        if (hp < 0) {
            break;
        }
        if (now_round != round - 1) {
            printf(" ");
        }
        hp = min(hp + regen, max_hp);
    }
    
    
}