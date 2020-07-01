#include <iostream>
#include <queue>
#define MAX 51
using namespace std;
typedef pair<int, int> pii;

int n, m, dy[4] = { 1,-1,0,0 }, dx[4] = { 0,0,1,-1 }, dist[MAX][MAX] = { 0, };
char mp[MAX][MAX];
pii src, dest;
queue<pii> water;

int bfs() {
	queue<pii> ret;
	ret.push(src);
	dist[src.first][src.second] = 1;	// 시작 위치 체크
	while (!ret.empty()) {
		// 물과 고슴도치가 동시에 움직인다고 가정
		// 물이 먼저 움직여야 정확한 결과를 알 수 있음
		int sz = water.size();	// 현재 저장된 위치만 이동시킴, 왜? => 매 분마다 움직이므로
		for (int i = 0; i < sz; ++i) {
			// 흔한 BFS
			int x = water.front().first, y = water.front().second;
			water.pop();
			for (int j = 0; j < 4; ++j) {
				int nx = x + dx[j], ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (mp[nx][ny] == 'D' || mp[nx][ny] == 'X' || mp[nx][ny] == '*') continue;
				// 물의 무한 증식(메모리 초과)를 막기 위해 현재 물인 곳도 걸러줌(mp[nx][ny] == '*')
				mp[nx][ny] = '*';
				water.push({ nx,ny });
			}
		}
		sz = ret.size();	// 물의 이동이 끝나면 고슴도치 이동
		for (int i = 0; i < sz; ++i) {
			// 흔한 BFS
			int x = ret.front().first, y = ret.front().second;
			ret.pop();
			for (int j = 0; j < 4; ++j) {
				int nx = x + dx[j], ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (mp[nx][ny] == '*' || mp[nx][ny] == 'X' || dist[nx][ny] != 0) continue;
				if (mp[nx][ny] == 'D') return dist[x][y];
				ret.push({ nx,ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> mp[i][j];
			if (mp[i][j] == 'D') dest = { i,j };	// 도착 위치 저장
			else if (mp[i][j] == 'S') src = { i,j };	// 시작 위치 저장
			else if (mp[i][j] == '*') water.push({ i,j });	// 물의 위치 저장
		}
	
	int ans = bfs();
	if (ans == -1) cout << "KAKTUS";
	else cout << ans;

	return 0;
}