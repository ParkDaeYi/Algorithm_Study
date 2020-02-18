#include <iostream>
#define MOD 10007
using namespace std;

int n, dp[1000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	dp[0] = 1; dp[1] = 3;
	for (int i = 2; i < n; ++i) dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;	
	cout << dp[n - 1];
	return 0;
}