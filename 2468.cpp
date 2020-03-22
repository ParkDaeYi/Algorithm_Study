#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, arr[100][100], _min = 101, _max, ans = 1;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool visited[100][100];

void dfs(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			_min = _min > arr[i][j] ? arr[i][j] : _min;
			_max = _max > arr[i][j] ? _max : arr[i][j];
		}
	}
	for (int t = _min; t <= _max; ++t) {
		vector<pii> vec;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (arr[i][j] <= t) arr[i][j] = 0;
				else vec.push_back({ i,j });
			}
		}
		int cnt = 0;
		for (pii next : vec) {
			if (visited[next.first][next.second]) continue;
			dfs(next.first, next.second);
			cnt++;
		}
		ans = ans > cnt ? ans : cnt;
		fill(&visited[0][0], &visited[n - 1][n], 0);
	}
	cout << ans;
	return 0;
}

void dfs(int y,int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; ++i) {
		int ny = y + dir[i][0], nx = x + dir[i][1];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx] || !arr[ny][nx]) continue;
		dfs(ny, nx);
	}
	return;
}