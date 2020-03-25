#include <iostream>
using namespace std;

int n, m, ans;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
char mp[21][21];
bool used[26];

void backtrack(int y, int x, int cnt) {
	if (ans < cnt) ans = cnt;
	for (int i = 0;i < 4;++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (used[mp[ny][nx] - 'A']) continue;
		used[mp[ny][nx] - 'A'] = 1;
		backtrack(ny, nx, cnt + 1);
		used[mp[ny][nx] - 'A'] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) cin >> mp[i][j];
	used[mp[0][0] - 'A'] = 1;
	backtrack(0, 0, 1);
	cout << ans;
	return 0;
}