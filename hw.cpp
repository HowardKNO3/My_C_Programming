#include <bits/stdc++.h>
#define INF 1000000000

using namespace std;

int main () {
	int n, m, cost;
	cin >> n >> m >> cost;
	int price[m] = {0};
	for (int i = 0; i < m; i++) {
		cin >> price[i];
	}
	int prob[m][n + 1] = {0};
	for (int i = 0; i < m; i++) {
		for (int j = 0; j <= n; j++) {
			cin >> prob[i][j]; 
		}
	}
	int min_buy = INF, max_revenue = -INF, min_price = INF;
	for (int now_price_index = 0; now_price_index < m; now_price_index++) {
		int now_price = price[now_price_index];
		for (int now_buy = 0; now_buy <= n; now_buy++) {
			int revenue = 0;
			for (int i = 0; i <= n; i++) {
				//cout << min(now_buy, i) << " " << now_price << " " << prob[now_price_index][i] << " ";
				//cout << endl;
				revenue += (min(now_buy, i) * now_price) * prob[now_price_index][i] / 100;
			}
			
			revenue -= cost * now_buy;
			if (revenue > max_revenue) {
				max_revenue = revenue;
				min_price = now_price;
				min_buy = now_buy;	
			} else if (revenue == max_revenue && now_price < min_price) {
				min_price = now_price;
				min_buy = now_buy;
			}
		}
	}
	cout << min_price << "," << min_buy << "," << max_revenue;
}
/*
4 3 30
100 200 300
30 10 40 5 15
30 40 20 5 5
50 20 20 10 0
*/
