#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[1001], cost[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> cost[i];
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= i; ++j) dp[i] = max(dp[i], dp[i - j] + cost[j]);
	cout << dp[n];
	return 0;
}