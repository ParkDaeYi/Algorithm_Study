#include <iostream>
#include <algorithm>
using namespace std;

int t, n, sti[2][100002], dp[2][100002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; ++i) {
			for (int j = 2; j < n + 2; ++j) cin >> sti[i][j];
		}
		for (int i = 2; i < n + 2; ++i) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sti[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sti[1][i];
		}
		dp[0][n + 1] > dp[1][n + 1] ? cout << dp[0][n + 1] << '\n' : cout << dp[1][n + 1] << '\n';
	}
	return 0;
}