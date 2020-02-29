#include <iostream>
using namespace std;

int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int n, ans;
char RGB[100][100];
bool rgb[100][100];

void dfs(int, int, char);
void dfs_rb(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> RGB[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (rgb[i][j]) continue;
			ans++;
			dfs(i, j, RGB[i][j]);
		}
	}
	cout << ans << ' ';
	ans = 0;
	fill(&rgb[0][0], &rgb[n - 1][n], 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (rgb[i][j]) continue;
			ans++;
			if (RGB[i][j] == 'B') dfs(i, j, 'B');
			else dfs_rb(i, j);
		}
	}
	cout << ans;
	return 0;
}

void dfs(int y, int x, char symbol) {
	for (int i = 0; i < 4; ++i) {
		int ny = y + dir[i][0], nx = x + dir[i][1];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (rgb[ny][nx] || symbol != RGB[ny][nx]) continue;
		rgb[ny][nx] = 1;
		dfs(ny, nx, symbol);
	}
}

void dfs_rb(int y, int x) {
	for (int i = 0; i < 4; ++i) {
		int ny = y + dir[i][0], nx = x + dir[i][1];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (rgb[ny][nx] || RGB[ny][nx] == 'B') continue;
		rgb[ny][nx] = 1;
		dfs_rb(ny, nx);
	}
}