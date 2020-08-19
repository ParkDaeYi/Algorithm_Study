#include <iostream>
#include <queue>
#include <algorithm>
#define N 50
using namespace std;
typedef pair<int, int> pii;

int n, m, ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
char map[N][N];

int solve(int y, int x) {
	int dist[N][N] = { 0, }, ret = 0;
	queue<pii> q;
	q.push({ y,x });
	dist[y][x] = 1;
	while (!q.empty()) {
		int cy = q.front().first, cx = q.front().second;
		q.pop();
		ret = max(ret, dist[cy][cx]);
		for (int i = 0;i < 4;++i) {
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (map[ny][nx] == 'W' || dist[ny][nx]) continue;
			dist[ny][nx] = dist[cy][cx] + 1;
			q.push({ ny,nx });
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0;i < n;++i) cin >> map[i];
	for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) if (map[i][j] == 'L') {
		if (i - 1 >= 0 && i + 1 < n && map[i - 1][j] == 'L' && map[i + 1][j] == 'L') continue;
		if (j - 1 >= 0 && j + 1 < m && map[i][j - 1] == 'L' && map[i][j + 1] == 'L') continue;
		// 상하, 좌우에 육지가 없을 경우에만 연산
		ans = max(ans, solve(i, j));
	}
	cout << ans - 1;
	return 0;
}