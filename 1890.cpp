#include <iostream>
using namespace std;
typedef long long int llt;

int n, dist[100][100];
llt ans[100][100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> dist[i][j];
	ans[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!ans[i][j] || !dist[i][j]) continue;
			int down = dist[i][j] + i, right = dist[i][j] + j;
			if (down < n) ans[down][j] += ans[i][j];
			if (right < n) ans[i][right] += ans[i][j];
		}
	}
	cout << ans[n - 1][n - 1];
	return 0;
}