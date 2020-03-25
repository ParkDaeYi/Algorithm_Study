#include <iostream>
#include <string>
using namespace std;
typedef long long int llt;

llt dp[32][32], I;
int N, L;
string ans;

void solve(int n, int m, llt v) {
	if (!n) return;
	if (!m) {
		for (int i = 0;i < n;++i) ans += '0';
		return;
	}
	llt chk = 0;
	for (int i = 0;i <= m;++i) chk += dp[n - 1][i];
	if (chk < v) {
		ans += '1';
		solve(n - 1, m - 1, v - chk);
	}
	else {
		ans += '0';
		solve(n - 1, m, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> L >> I;
	for (int i = 0;i < N;++i) {
		for (int j = 0;j <= i;++j) {
			if (!j || i == j) dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	solve(N, L, I);
	cout << ans;
	return 0;
}