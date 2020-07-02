#include <iostream>
using namespace std;
typedef long long int llt;

llt dp[91];	// long long int 쓰는게 핵심
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[0] = 0;
	dp[1] = dp[2] = 1;
	for (int i = 3; i < n + 1; ++i) dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n];

	return 0;
}