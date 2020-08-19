#include <iostream>
#include <algorithm>
#define N 501
using namespace std;

int n, m, map[N][N], ans;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visit[N][N];

// 백트래킹을 통해 상하좌우로 4번씩 실행을 하게 되면
// 'ㅜ' 이 도형을 제외한 나머지 도형은 표현 가능
int dfs(int y, int x, int depth) {
	if (depth == 3) return map[y][x];

	int ret = 0;
	for (int i = 0;i < 4;++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visit[ny][nx]) continue;
		visit[ny][nx] = 1;
		ret = max(ret, map[y][x] + dfs(ny, nx, depth + 1));
		visit[ny][nx] = 0;
	}
	return ret;
}

// 'ㅜ' 도형은 따로 연산
int block(int y, int x) {
	int ret = 0;

	// ㅜ
	if (x > 0 && y + 1 < n && x + 1 < m) ret = max(ret, map[y][x - 1] + map[y][x] + map[y][x + 1] + map[y + 1][x]);
	// ㅏ
	if (y > 0 && y + 1 < n && x + 1 < m) ret = max(ret, map[y - 1][x] + map[y][x] + map[y + 1][x] + map[y][x + 1]);
	// ㅓ
	if (y > 0 && x > 0 && y + 1 < n) ret = max(ret, map[y][x - 1] + map[y][x] + map[y - 1][x] + map[y + 1][x]);
	// ㅗ
	if (x > 0 && y > 0 && x + 1 < m) ret = max(ret, map[y][x - 1] + map[y][x] + map[y - 1][x] + map[y][x + 1]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) cin >> map[i][j];
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			visit[i][j] = 1;
			ans = max(ans, max(dfs(i, j, 0), block(i, j)));
			visit[i][j] = 0;
		}
	}
	cout << ans;
	return 0;
}
