#include <iostream>
#define INF 2e9
#define MAX 5001
using namespace std;

int t, n, dp[MAX][MAX], opt[MAX][MAX], sum[MAX];

//Knuth's optimization
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (cin >> t; t--;) {
		cin >> n;
		for (int i = 1, num; i <= n; ++i) cin >> num, sum[i] = sum[i - 1] + num;
		for (int i = 0; i < n; ++i) opt[1][i] = i + 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j + i <= n; ++j) {
				dp[i][j] = INF;
				for (int k = opt[i - 1][j]; k <= opt[i - 1][j + 1]; ++k) {
					if (dp[i][j] > dp[k - j][j] + dp[i - k + j][k]) {
						dp[i][j] = dp[k - j][j] + dp[i - k + j][k];
						opt[i][j] = k;
					}
				}
				dp[i][j] += sum[i + j] - sum[j];
			}
		}
		cout << dp[n][0] << '\n';
	}
	return 0;
}