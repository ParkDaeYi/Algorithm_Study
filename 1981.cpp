#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, _map[111][111];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int visit[111][111];
vector<int> range;

bool bfs(int s, int e) {
	if (s > _map[0][0] || _map[0][0] > e) return 0;
	fill(&visit[0][0], &visit[n][n - 1], 0);
	visit[0][0] = 1;
	queue<pii> q;
	q.push(pii(0, 0));
	while (!q.empty()) {
		int cy = q.front().first, cx = q.front().second;
		q.pop();
		if (cy == n - 1 && cx == n - 1) return 1;
		for (int i = 0; i < 4; ++i) {
			int ny = cy + dy[i], nx = cx + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (s > _map[ny][nx] || _map[ny][nx] > e) continue;
			if (visit[ny][nx]) continue;
			visit[ny][nx] = 1;
			q.push(pii(ny, nx));
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> _map[i][j];
			range.push_back(_map[i][j]);
		}
	}
	sort(range.begin(), range.end());
	range.erase(unique(range.begin(), range.end()), range.end());
	int low = 0, high = 0, ans = 987654321, sz = range.size();
	while (low <= high && high < sz) {
		if (bfs(range[low], range[high])) ans = min(ans, range[high] - range[low++]);
		else high++;
	}
	cout << ans;
	return 0;
}