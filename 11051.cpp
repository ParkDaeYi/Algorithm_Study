#include <iostream>
#define MOD 10007
using namespace std;

int n, k, dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	dp[0][0] = 0;
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (j == 0 || j == i) {
				dp[i][j] = 1; continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
		}
	}
	cout << dp[n][k];
	return 0;
}