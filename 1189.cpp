#include <iostream>
using namespace std;

int n, m, k, dist[5][5];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
char mp[5][5];

int backtrack(int y, int x) {
	if (y == 0 && x == m - 1) return dist[y][x] == k ? 1 : 0;
	int ret = 0;
	for (int i = 0;i < 4;++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (mp[ny][nx] == 'T') continue;
		if (!dist[ny][nx]) {
			dist[ny][nx] += dist[y][x] + 1;
			ret += backtrack(ny, nx);
			dist[ny][nx] = 0;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) cin >> mp[i][j];
	dist[n - 1][0] = 1;
	cout << backtrack(n - 1, 0);
	return 0;
}