#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int tomato[1000][1000], ans, n, m;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	queue<pii> q;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) q.push(make_pair(i, j));
		}
	}

	while (!q.empty()) {
		int cy = q.front().first, cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dir[i][0], nx = cx + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (tomato[ny][nx]) continue;
			q.push(make_pair(ny, nx)); tomato[ny][nx] = tomato[cy][cx] + 1;
		}
	}

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!tomato[i][j]) {
				cout << -1;
				return 0;
			}
			else if (ans < tomato[i][j]) ans = tomato[i][j];
		}
	}
	cout << ans - 1;
	return 0;
}