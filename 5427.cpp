#include <iostream>
#include <queue>
#define MAX 1000
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> ppiii;

pii s;
bool visited[MAX][MAX];
char _map[MAX][MAX];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int t, w, h, fire[MAX][MAX];

int bfs();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> w >> h;
		fill(&fire[0][0], &fire[h - 1][w], INF);
		fill(&_map[0][0], &_map[h - 1][w], 0);
		fill(&visited[0][0], &visited[h - 1][w], 0);
		queue<pii> q;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> _map[i][j];
				if (_map[i][j] == '@') s = make_pair(i, j);
				if (_map[i][j] == '*') {
					q.push({ i,j });
					fire[i][j] = 1;
				}
			}
		}
		while (!q.empty()) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int ny = y + dir[i][0], nx = x + dir[i][1];
				if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
				if (_map[ny][nx] == '#') continue;
				if (fire[ny][nx] > fire[y][x] + 1) {
					q.push({ ny,nx });
					fire[ny][nx] = fire[y][x] + 1;
				}
			}
		}
		int ans = bfs();
		ans ? cout << ans << '\n' : cout << "IMPOSSIBLE\n";
	}
	return 0;
}

int bfs() {
	queue<ppiii> q;
	q.push(ppiii(pii(s), 1));
	visited[s.first][s.second] = 1;
	while (!q.empty()) {
		int y = q.front().first.first, x = q.front().first.second, cnt = q.front().second;
		q.pop();
		if (y == 0 || y == h - 1 || x == 0 || x == w - 1) return cnt;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dir[i][0], nx = x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (_map[ny][nx] == '#' || _map[ny][nx] == '*' || visited[ny][nx]) continue;
			if (fire[ny][nx] > cnt + 1) {
				visited[ny][nx] = 1;
				q.push(ppiii(pii(ny, nx), cnt + 1));
			}
		}
	}
	return 0;
}