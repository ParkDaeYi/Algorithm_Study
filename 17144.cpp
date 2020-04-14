#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int r, c, t, arr[51][51], ans;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
vector<pii> cleaner;
queue<pii> q;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> r >> c >> t;
	for (int i = 0; i < r; ++i) 
		for (int j = 0; j < c; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) cleaner.push_back(pii(i, j));
		}
	while (t--) {
		int copyArr[51][51] = { 0, };
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) copyArr[i][j] = arr[i][j];

		for (int i = 0; i < r; ++i) 
			for (int j = 0; j < c; ++j) {
				if (!arr[i][j] || arr[i][j] == -1) continue;
				q.push(pii(i, j));
			}
		
		while (!q.empty()) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			int div = copyArr[y][x] / 5;
			if (!div) continue;
			for (int i = 0; i < 4; ++i) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
				if (arr[ny][nx] == -1) continue;
				arr[ny][nx] += div;
				arr[y][x] -= div;
			}
		}

		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) copyArr[i][j] = arr[i][j];
		int y = cleaner[0].first, x = cleaner[0].second + 1;
		arr[y][x] = 0;
		for (int i = 0; i < 4; ++i) 
			while (1) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny == cleaner[0].first && nx == cleaner[0].second) break;
				if (ny < 0 || ny >= r || nx < 0 || nx >= c) break;
				arr[ny][nx] = copyArr[y][x];
				y = ny, x = nx;
			}
		y = cleaner[1].first, x = cleaner[1].second + 1;
		arr[y][x] = 0;
		for (int i = 0, cnt = 0; cnt < 4; i = (i + 3) % 4, ++cnt)
			while (1) {
				int ny = y + dy[i], nx = x + dx[i];
				if (ny == cleaner[1].first && nx == cleaner[1].second) break;
				if (ny < 0 || ny >= r || nx < 0 || nx >= c) break;
				arr[ny][nx] = copyArr[y][x];
				y = ny, x = nx;
			}
	}
	for (int i = 0; i < r; ++i) 
		for (int j = 0; j < c; ++j) {
			if (!arr[i][j] || arr[i][j] == -1) continue;
			ans += arr[i][j];
		}
	cout << ans;

	return 0;
}