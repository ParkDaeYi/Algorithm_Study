#include <iostream>
#include <algorithm>
#define MAX 1002
using namespace std;
typedef long long int llt;

int n, m, arr[MAX], opt[MAX][MAX];
llt dp[MAX][MAX];
const llt INF = 9000000000000000000LL;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m >> n;
	n++;
	for (int i = 1; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n; ++i) opt[1][i] = i + 1;
	arr[n] = m;
	sort(arr, arr + n + 1);
	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j + i <= n; ++j) {
			dp[i][j] = INF;
			for (int k = opt[i - 1][j]; k <= opt[i - 1][j + 1]; ++k) {
				if (dp[i][j] > dp[k - j][j] + dp[i - k + j][k]) {
					dp[i][j] = dp[k - j][j] + dp[i - k + j][k];
					opt[i][j] = k;
				}
			}
			dp[i][j] += arr[i + j] - arr[j];
		}
	}
	cout << dp[n][0];
	return 0;
}