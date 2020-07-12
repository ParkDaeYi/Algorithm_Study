#include <iostream>
using namespace std;
typedef long long int llt;

int n, arr[100];
llt dp[100][21];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;++i) cin >> arr[i];

	dp[0][arr[0]]++;
	// 마지막은 = 이므로 n - 1까지만 돌림
	for (int i = 1;i < n - 1;++i) {
		for (int j = 0;j < 21;++j) {
			if (!dp[i - 1][j]) continue;
			// 0~20이 되는 모든 경우를 찾음
			if (j + arr[i] < 21) dp[i][j + arr[i]] += dp[i - 1][j];
			if (j - arr[i] >= 0) dp[i][j - arr[i]] += dp[i - 1][j];
		}
	}
	cout << dp[n - 2][arr[n - 1]];
	return 0;
}