#include <iostream>
using namespace std;
typedef pair<int, int> pii;

int n, m, mp[501][501], ans;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool used[501][501];

int max_int(int a, int b) { return a > b ? a : b; }

int dfs(int y, int x, int depth) {
	if (depth == 3) return mp[y][x];

	int ret = 0;
	for (int i = 0;i < 4;++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (used[ny][nx]) continue;
		used[ny][nx] = 1;
		ret = max_int(ret, mp[y][x] + dfs(ny, nx, depth + 1));
		used[ny][nx] = 0;
	}
	return ret;
}

int block(int y, int x) {
	int ret = 0;
	//ㅜ
	if (x > 0 && y < n - 1 && x < m - 1)
		ret = max_int(ret, mp[y][x - 1] + mp[y][x] + mp[y][x + 1] + mp[y + 1][x]);
	//ㅗ
	if (x > 0 && y > 0 && x < m - 1)
		ret = max_int(ret, mp[y][x - 1] + mp[y][x] + mp[y][x + 1] + mp[y - 1][x]);
	//ㅏ
	if (y > 0 && x < m - 1 && y < n - 1)
		ret = max_int(ret, mp[y + 1][x] + mp[y][x] + mp[y - 1][x] + mp[y][x + 1]);
	//ㅓ
	if (x > 0 && y > 0 && y < n - 1)
		ret = max_int(ret, mp[y][x] + mp[y][x - 1] + mp[y - 1][x] + mp[y + 1][x]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) cin >> mp[i][j];
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			used[i][j] = 1;
			ans = max_int(ans, dfs(i, j, 0));
			ans = max_int(ans, block(i, j));
			used[i][j] = 0;
		}
	}
	cout << ans;

	return 0;
}