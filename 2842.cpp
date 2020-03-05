#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

pii src;
int n, h[50][50], kcnt, ans = 1e9 + 1;
int dx[8] = { 1,-1,0,0,1,1,-1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,1,-1 };
bool visited[50][50];
char _map[50][50];
vector<int> range;

int dfs(int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> _map[i][j];
			if (_map[i][j] == 'P') src = make_pair(i, j);
			if (_map[i][j] == 'K') kcnt++;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> h[i][j];
			range.push_back(h[i][j]);
		}
	}
	sort(range.begin(), range.end());
	range.erase(unique(range.begin(), range.end()), range.end());
	int low = 0, high = 0, sz = range.size();
	while (low <= high && high < sz) {
		fill(&visited[0][0], &visited[n - 1][n], 0);
		visited[src.first][src.second] = 1;
		if (dfs(src.first, src.second, range[low], range[high]) == kcnt) {
			ans = min(ans, range[high] - range[low++]);
			if (low > high && low < sz) high = low;
		}
		else high++;
	}
	cout << ans;
	return 0;
}

int dfs(int y, int x, int start, int end) {
	if (start > h[y][x] || h[y][x] > end) return 0;
	int ret = 0;
	if (_map[y][x] == 'K') ret++;
	for (int i = 0; i < 8; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		ret += dfs(ny, nx, start, end);
	}
	return ret;
}