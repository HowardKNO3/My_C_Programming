#include <stdio.h>
#define INF 1000000000

int calculate_dis (int x1, int y1, int x2, int y2) {
    int x_diff = x1 - x2;
    if(x_diff < 0) {
        x_diff = -x_diff;
    }
    int y_diff = y1 - y2;
    if(y_diff < 0) {
        y_diff = -y_diff;
    }
    return x_diff + y_diff;
}

int main(){
    int n;
    scanf("%d", &n);
    int parking[10][3] = {0};
    int used[10] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &parking[i][0], &parking[i][1], &parking[i][2]);
        used[i] = 0;
    }
    int b;
    scanf("%d", &b);
    
    for (int i = 0; i < b; i++)  {
        int x, y;
        int target_index = -1;
        int target_dis = INF;
        scanf("%d%d", &x, &y);
        for (int j = 0; j < n; j++) {
            if (parking[j][2] == used[j]) {
                continue;
            }
            if (calculate_dis(x, y, parking[j][0], parking[j][1]) < target_dis) {
                target_dis = calculate_dis(x, y, parking[j][0], parking[j][1]);
                target_index = j;
            }
            if (calculate_dis(x, y, parking[j][0], parking[j][1]) == target_dis){
            	if(parking[j][0] < parking[target_index][0]) {
                	target_index = j;
				}
				if(parking[j][0] == parking[target_index][0] && parking[j][1] < parking[target_index][1]) {
                	target_index = j;
				}
			}
        }
        
        used[target_index]++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", used[i]);
    }
    
}
