#include <iostream>
using namespace std;

int n, num[1000], dp[1000], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> num[i];
	for (int i = 0; i < n; ++i) {
		dp[i] = num[i];
		for (int j = 0; j < i; ++j) {
			if (num[i] > num[j] && dp[j] + num[i] > dp[i]) dp[i] = dp[j] + num[i];
		}
		ans = ans > dp[i] ? ans : dp[i];
	}
	cout << ans;
	return 0;

}