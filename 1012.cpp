#include <iostream>
using namespace std;

int visited[50][50], bea[50][50];
int t, n, m, k, cnt;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

void dfs(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		cnt = 0;
		for (int i = 0, y, x; i < k; ++i) {
			cin >> y >> x;
			bea[y][x] = 1;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (visited[i][j] || !bea[i][j]) continue;
				dfs(i, j);
				cnt++;
			}
		}
		cout << cnt << '\n';
		fill(&bea[0][0], &bea[n - 1][m], 0);
		fill(&visited[0][0], &visited[n - 1][m], 0);
	}
	return 0;
}

void dfs(int y, int x) {
	if (visited[y][x]) return;
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dir[i][0], nx = x + dir[i][1];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx] || !bea[ny][nx]) continue;
		dfs(ny, nx);
	}
	return;
}