#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, h[50][50], kcnt;	// h: 고도, kcnt: 집의 수
int dy[8] = { 1,-1,0,0,1,1,-1,-1 };	// 수평 수직 대각
int dx[8] = { 0,0,1,-1,1,-1,1,-1 };
char p[50][50];	// 위치
bool visit[50][50];	// 방문 여부
pii src;
vector<int> tired;

int dfs(int y, int x, int left, int right) {
	if (h[y][x] < left || right < h[y][x]) return 0;	// 범위 초과시 return
	int ret = 0;
	if (p[y][x] == 'K') ret++;
	for (int i = 0; i < 8; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visit[ny][nx]) continue;
		visit[ny][nx] = 1;	// 주어진 범위로만 이동하므로 visit을 다시 0으로 해줄 필요 없음
		ret += dfs(ny, nx, left, right);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> p[i][j];
			if (p[i][j] == 'P') src = { i,j };	// 시작 지점
			else if (p[i][j] == 'K') kcnt++;	// 집 카운팅
		}

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) { cin >> h[i][j]; tired.push_back(h[i][j]); }
	sort(tired.begin(), tired.end());
	tired.erase(unique(tired.begin(), tired.end()), tired.end());	// 연산 수를 줄이기 위해 중복 제거

	int low = 0, high = 0, sz = tired.size(), ans = 1e9;
	while (low <= high && high < sz) {
		fill(&visit[0][0], &visit[n - 1][n], 0);
		visit[src.first][src.second] = 1;
		if (dfs(src.first, src.second, tired[low], tired[high]) == kcnt) {
			ans = min(ans, tired[high] - tired[low++]);
			if (low > high && low < sz) high = low;
		}
		else high++;
	}
	cout << ans;
	return 0;
}