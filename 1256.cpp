#include <iostream>
#include <algorithm>
using namespace std;

int dp[201][201], n, m, k;

inline int nHk(int a, int b) { return dp[a + b][b]; }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2;i <= n + m;++i) 
		for (int j = 0;j <= i;++j) {
			if (!j || i == j) dp[i][j] = 1;
			else dp[i][j] = min((int)1e9, dp[i - 1][j - 1] + dp[i - 1][j]);	// k는 십억보다 작거나 같음
		}

	if (nHk(n, m) < k) cout << -1;	// 사전에 수록된 갯수보다 k보다 작을 경우 (중복조합)
	else {
		while (n || m) {
			if (!n) {	// a 다 씀
				cout << 'z';
				m -= 1;
			}
			else if (!m) {	// z 다 씀
				cout << 'a';
				n -= 1;
			}
			else if (nHk(n - 1, m) < k) {	// a의 개수가 k보다 작을 경우
				cout << 'z';
				k -= nHk(n - 1, m);
				m -= 1;
			}
			else {	// a의 개수가 k보다 작거나 같을 경우
				cout << 'a';
				n -= 1;
			}
		}
	}
	return 0;
}