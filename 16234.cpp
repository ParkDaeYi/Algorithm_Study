#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;

int n, l, r, cnt, mp[51][51];
bool visit[51][51];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
queue <pii> country;

bool bfs(int y, int x) {
	queue <pii> q;
	q.push(pii(y, x));
	visit[y][x] = 1;
	vector <pii> v;
	v.push_back(pii(y,x));
	int sum = mp[y][x];
	while (!q.empty()) {
		int cy = q.front().first, cx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visit[ny][nx]) continue;
			int diff = abs(mp[cy][cx] - mp[ny][nx]);
			if (diff < l || diff > r) continue;
			v.push_back(pii(ny, nx));
			sum += mp[ny][nx];
			visit[ny][nx] = true;
			q.push(pii(ny, nx));
		}
	}
	if (v.size() > 1) {
		int num = sum / v.size();
		for (pii p : v) {
			mp[p.first][p.second] = num;
			country.push(p);
		}
		return 1;
	}
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> mp[i][j];
			country.push({ i,j });
		}

	while (1)
	{
		bool flag = 0;
		int sz = country.size();
		for (int i = 0;i < sz;++i) {
			pii c = country.front();
			country.pop();
			if (visit[c.first][c.second]) continue;
			if (bfs(c.first, c.second)) flag = 1;
		}
		if (!flag) break;
		cnt++;
		fill(&visit[0][0], &visit[n - 1][n], 0);
	}
	cout << cnt;
	return 0;
}