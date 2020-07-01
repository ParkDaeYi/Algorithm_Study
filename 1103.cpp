#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 50
using namespace std;

int n, m, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, dp[MAX][MAX];
char mp[MAX][MAX];
bool visit[MAX][MAX], finish[MAX][MAX], roop;
// visit: 최초 방문, finish: 최종 방문, roop: 무한으로 이동 가능 여부

int solve_1(int y,int x) {
	// BFS, DFS
	visit[y][x] = dp[y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + (mp[y][x] - '0') * dx[i], ny = y + (mp[y][x] - '0') * dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		if (visit[ny][nx]) {
			if (finish[ny][nx]) dp[y][x] = max(dp[y][x], dp[ny][nx] + 1);
			else roop = 1;	// 방문한 곳인데 끝난 지점이 아닐 경우
		}
		else dp[y][x] = max(dp[y][x], solve_1(ny, nx) + 1);	// 방문한 곳이 아닐 경우 더 이동이 가능함
	}
	finish[y][x] = 1;	// 더 이상 이동할 수 있는 곳이 없음
	return dp[y][x];
}

int main_1() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> mp[i][j];
			if (mp[i][j] == 'H') visit[i][j] = finish[i][j] = 1;	// 구멍 체크
		}

	int ans = solve_1(0, 0);
	cout << (roop ? -1 : ans);
	return 0;
}

int n, m, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 }, dp[MAX][MAX], mp[MAX][MAX];
bool visit[MAX][MAX];

int solve_2(int y,int x) {
	// Backtracking
	if (y < 0 || x < 0 || y >= n || x >= m || !mp[y][x]) return 0;
	if (visit[y][x]) return 1e9;	// 무한으로 이동 가능
	if (dp[y][x]) return dp[y][x];	// 백트랙킹이라 dp에 값이 존재함
	visit[y][x] = 1;
	for (int i = 0; i < 4; ++i) dp[y][x] = max(dp[y][x], solve_2(y + mp[y][x] * dy[i], x + mp[y][x] * dx[i]) + 1);
	visit[y][x] = 0;
	return dp[y][x];
}

int main_2() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			if (c <= '9') mp[i][j] = c - '0';	// 구멍만 0으로 되어 있음
		}

	int ans = solve_2(0, 0);
	cout << (ans >= 1e9 ? -1 : ans);
	return 0;
}