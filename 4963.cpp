#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
typedef pair<int, int> pii;

int w, h, map[51][51];
int dy[8] = { 1,0,-1,0,1,1,-1,-1 };
int dx[8] = { 0,1,0,-1,1,-1,1,-1 };
bool visit[51][51];

void bfs(int y, int x) {
	visit[y][x] = 1;
	queue<pii> q;
	q.push({ y,x });
	while (!q.empty()) {
		int cy = q.front().first, cx = q.front().second;
		q.pop();
		for (int i = 0;i < 8;++i) {
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (!map[ny][nx] || visit[ny][nx]) continue;
			visit[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while ((cin >> w >> h)) {
		if (!w && !h) break;
		for (int i = 0;i < h;++i) for (int j = 0;j < w;++j) cin >> map[i][j];
		memset(visit, 0, sizeof(visit));
		int cnt = 0;
		for (int i = 0;i < h;++i) for (int j = 0;j < w;++j) {
			if (!map[i][j] || visit[i][j]) continue;
			bfs(i, j);
			++cnt;
		}
		cout << cnt << '\n';
	}
	return 0;
}