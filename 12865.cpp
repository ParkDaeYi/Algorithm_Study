#include <iostream>
using namespace std;

int dp[100001], n, k, w, v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	while (n--) {
		cin >> w >> v;
		for (int i = k; i >= w; --i) dp[i] = dp[i] > dp[i - w] + v ? dp[i] : dp[i - w] + v;
	}
	cout << dp[k];
	return 0;
}