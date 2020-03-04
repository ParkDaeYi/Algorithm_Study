#include <iostream>
#include <queue>
using namespace std;

int cache[500][500], n, m, arr[500][500];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> arr[i][j];
	fill(&cache[0][0], &cache[n - 1][m], -1);
	cout << dfs(n - 1, m - 1);
	return 0;
}

int dfs(int y, int x) {
	if (cache[y][x] != -1) return cache[y][x];
	if (!x && !y) return 1;
	cache[y][x] = 0;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (arr[ny][nx] > arr[y][x]) cache[y][x] += dfs(ny, nx);
	}
	return cache[y][x];
}