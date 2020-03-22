#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int trash[101][101], n, m, k, ans = 1, cnt;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int visited[101][101];

void dfs(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0, y, x; i < k; ++i) {
		cin >> y >> x;
		trash[y][x] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (visited[i][j] || !trash[i][j]) continue;
			cnt = 0;
			dfs(i, j);
			ans = max(ans, cnt);
		}
	}
	cout << ans;
	return 0;
}

void dfs(int y, int x) {
	for (int i = 0; i < 4; ++i) {
		int ny = y + dir[i][0], nx = x + dir[i][1];
		if (ny<1 || nx<1 || ny>n || nx>m) continue;
		if (visited[ny][nx] || !trash[ny][nx]) continue;
		visited[ny][nx] = 1;
		cnt++;
		dfs(ny, nx);
	}
}