#include <iostream>
#define MOD 10007
using namespace std;

int n, dp[1001][10], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	fill(&dp[0][0], &dp[n][10], 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 8; j >= 0; --j) dp[i][j] = (dp[i - 1][j] + dp[i][j + 1]) % MOD;
	}
	cout << dp[n][0];
	return 0;
}