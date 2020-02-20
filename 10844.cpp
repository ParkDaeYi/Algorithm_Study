#include <iostream>
#define MOD 1000000000
using namespace std;
typedef long long int llt;

int n, dp[101][11];
llt ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= 9; ++i) dp[1][i] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 9; ++j) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
	}
	for (int i = 0; i < 10; ++i) ans += dp[n][i];
	cout << ans % MOD;
	return 0;
}