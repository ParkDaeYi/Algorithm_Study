#include <iostream>
#define MOD 10007
using namespace std;

int n, k, dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	dp[0][0] = dp[1][0] = dp[1][1] = 1;
	// 가장 기본적인 파스칼 삼각형(이항 계수)
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = 1;	// j가 0이거나 i==j 이면 1
		for (int j = 1; j <= i; ++j) {
			if (i == j) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;	// 이항 계수 1이랑 다른 건 딱히 없음
		}
	}
	cout << dp[n][k];

	return 0;
}