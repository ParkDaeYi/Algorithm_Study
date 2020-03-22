#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int n, k, dp[10001], num;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	fill(dp, dp + k + 1, MAX);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		for (int j = num; j <= k; ++j) dp[j] = min(dp[j - num] + 1, dp[j]);
	}
	if (dp[k] == MAX) cout << -1;
	else cout << dp[k];
	return 0;
}