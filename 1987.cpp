#include <iostream>
#define N 20
using namespace std;

int n, m, map[N][N], ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[26];

void solve(int y, int x, int dist) {
	if (ans < dist) ans = dist;
	for (int i = 0;i < 4;++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visit[map[ny][nx]]) continue;
		visit[map[ny][nx]] = 1;
		solve(ny, nx, dist + 1);
		visit[map[ny][nx]] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	char c;
	for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) {
		cin >> c;
		map[i][j] = c - 'A';
	}
	visit[map[0][0]] = 1;
	solve(0, 0, 1);
	cout << ans;
	return 0;
}
