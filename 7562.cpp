#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1e9+1
using namespace std;
typedef pair<int, int> pii;

int t, n, cur_y, cur_x, dest_y, dest_x, cache[300][300];
pii dir[8] = { {2,1},{1,2},{-1,2},{-2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
bool visited[300][300];

int main() {
 	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> cur_y >> cur_x >> dest_y >> dest_x;
		fill(&cache[0][0], &cache[n - 1][n], MAX);
		fill(&visited[0][0], &visited[n - 1][n], 0);
		queue<pii> q;
		q.push({ cur_y,cur_x });
		cache[cur_y][cur_x] = 0;
		visited[cur_y][cur_x] = 1;
		while (!q.empty()) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			if (y == dest_y && x == dest_x) {
				cout << cache[y][x] << '\n';
				break;
			}
			for (int i = 0; i < 8; ++i) {
				int ny = y + dir[i].first, nx = x + dir[i].second;
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (visited[ny][nx]) continue;
				visited[ny][nx] = 1;
				q.push({ ny,nx });
				cache[ny][nx] = min(cache[y][x] + 1, cache[ny][nx]);
			}
		}
	}
	return 0;
}