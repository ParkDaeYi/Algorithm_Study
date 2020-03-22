#include <iostream>
using namespace std;
typedef long long int llt;

int n;
llt dp[90];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	dp[0] = dp[1] = 1;
	for (int i = 2; i < n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n - 1];
	return 0;
}