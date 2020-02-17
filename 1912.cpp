#include <iostream>
using namespace std;

int dp[100001], num[100001], n, ret;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> num[i];
	dp[0] = ret = num[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = dp[i - 1] + num[i] > num[i] ? dp[i - 1] + num[i] : num[i];
		ret = ret > dp[i] ? ret : dp[i];
	}
	cout << ret;
	return 0;
}