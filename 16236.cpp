#include <stdio.h>
#include <memory.h>
#include <functional>
#include <queue>
#pragma warning(disable:4996)
using namespace std;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> ppiii;

class point {
public:
	int y, x, time;
	point(int y = 0, int x = 0, int time = 0) :y(y), x(x), time(time) {}
	bool operator<(const point& p) const {
		if (time == p.time && y == p.y) return x > p.x;
		else if (time == p.time) return y > p.y;
		else return time > p.time;
	}
};
int n, mp[21][21];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool visit[21][21];
pii src;

int main() {
	//freopen("p679.inp", "r", stdin);
	//freopen("p679.out", "w", stdout);

	
	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &mp[i][j]);
			if (mp[i][j] == 9) {
				src = pii(i, j);
				mp[i][j] = 0;
			}
		}
	}

	queue<ppiii> q;
	q.push(ppiii(src, 2));
	int ans = 0, cnt = 0;
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int sz = q.front().second;
		q.pop();
		memset(visit, 0, sizeof(visit));
		priority_queue<point> pq;
		pq.push(point(y, x, 0));
		visit[y][x] = 1;
		while (!pq.empty()) {
			int cycle = pq.size();
			priority_queue<ppiii, vector<ppiii>, greater<ppiii>> eat;
			for (int i = 0; i < cycle; ++i) {
				int cy = pq.top().y, cx = pq.top().x;
				int ctime = pq.top().time;
				pq.pop();
				for (int i = 0; i < 4; ++i) {
					int ny = cy + dy[i], nx = cx + dx[i];
					if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
					if (visit[ny][nx] || mp[ny][nx] > sz) continue;
					pq.push(point(ny, nx, ctime + 1));
					visit[ny][nx] = 1;
					if (0 < mp[ny][nx] && mp[ny][nx] < sz) eat.push(ppiii(pii(ny, nx), ctime + 1));
				}
			}
			if (!eat.empty()) {
				if (++cnt == sz) {
					q.push(ppiii(eat.top().first, sz + 1));
					cnt = 0;
				}
				else q.push(ppiii(eat.top().first, sz));
				mp[eat.top().first.first][eat.top().first.second] = 0;
				ans += eat.top().second;
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}