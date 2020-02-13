#include <iostream>
using namespace std;

char map[5][5];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }, ans;
bool visited[5][5], seven[5][5];

void dfs(int, int, int, int);
void solve(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) cin >> map[i][j];
	dfs(0, 0, 0, 0);
	cout << ans;
	return 0;
}

void dfs(int S, int Y, int y,int x) {
	if (Y > 3) return;
	if (S + Y == 7) {
		int cnt = 0;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (!visited[i][j] || seven[i][j]) continue;
				seven[i][j] = 1;
				++cnt;
				solve(i, j);
			}
		}
		fill(&seven[0][0], &seven[4][5], 0);
		if (cnt == 1) ++ans;
		return;
	}
	for (int i = y; i < 5; ++i) {
		for (int j = x; j < 5; ++j) {
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			if (map[i][j] == 'S') dfs(S + 1, Y, i, j);
			else dfs(S, Y + 1, i, j);
			visited[i][j] = 0;
		}
		x = 0;
	}
	return;
}

void solve(int y, int x) {
	for (int i = 0; i < 4; ++i) {
		int ny = y + dir[i][0], nx = x + dir[i][1];
		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
		if (!visited[ny][nx] || seven[ny][nx]) continue;
		seven[ny][nx] = 1;
		solve(ny, nx);
	}
	return;
}