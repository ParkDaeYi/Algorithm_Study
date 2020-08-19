#include <iostream>
#include <algorithm>
#define N 15
using namespace std;

int n, dp[N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, a, b;i < n;++i) {
		cin >> a >> b;
		int c = dp[i] + b;
		for (int j = a + i;j <= n;++j) dp[j] = max(dp[j], c);
	}
	cout << dp[n];
	return 0;
}