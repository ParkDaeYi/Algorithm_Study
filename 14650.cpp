#include <iostream>
using namespace std;

int n, ans;

void solve(int idx, int num) {
	if (idx == n) {
		if (num % 3 == 0) ++ans;
		return;
	}
	solve(idx + 1, num + 0);
	solve(idx + 1, num + 1);
	solve(idx + 1, num + 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	solve(1, 1); solve(1, 2);
	cout << ans;
	return 0;
}

// dp
// dp[i][j] 는 i의 자릿수 중 모든 자릿수(경우)를 더한 뒤 3으로 나눈 나머지가 j가 되는 수의 경우의 수
int main_1() {
	cin >> n;
	int dp[10][3];
	dp[1][0] = 0;
	dp[1][1] = dp[1][2] = 1;
	for (int i = 2;i <= n;++i) {
		for (int j = 0;j < 3;++j) dp[i][j] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
	}
	cout << dp[n][0];
	return 0;
}