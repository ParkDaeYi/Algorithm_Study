#include <iostream>
#define INF 2e9
using namespace std;

int dp[501][501], sum[501], t, n;

inline int min_int(int a, int b) {
	return a > b ? b : a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1, num; i <= n; ++i) {
			cin >> num;
			sum[i] = sum[i - 1] + num;
		}
		//Kruth's Optimization
		for (int i = 1; i <= n; ++i) {
			for (int a = 1; a + i <= n; ++a) {
				int b = a + i;
				dp[a][b] = INF;
				for (int mid = a; mid < b; ++mid) 
					dp[a][b] = min_int(dp[a][b], dp[a][mid] + dp[mid + 1][b] + sum[b] - sum[a - 1]);		
			}
		}
		cout << dp[1][n] << '\n';
	}
	return 0;
}