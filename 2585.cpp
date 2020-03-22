#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, k;
pii pos[1002];
bool visited[1002];

int d(pii a, pii b) {
	int x = b.first - a.first, y = b.second - a.second;
	return (int)ceil(sqrt(x * x + y * y) / 10);
}
bool bfs(int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	pos[0] = pii(0, 0);
	for (int i = 1; i <= n; ++i) cin >> pos[i].first >> pos[i].second;
	pos[n + 1] = pii(1e4, 1e4);
	int left = 1, right = d(pii(0, 0), pii(1e4, 1e4));
	while (left <= right) {
		int mid = (left + right) >> 1;
		if (bfs(mid)) right = mid - 1;
		else left = mid + 1;
	}
	cout << left;
	return 0;
}

bool bfs(int cost) {
	fill(visited, visited + n + 2, 0);
	queue<pii> q;
	q.push({ 0,0 });
	while (!q.empty()) {
		int from = q.front().first, cnt = q.front().second;
		q.pop();
		if (from == n + 1) {
			if (cnt <= k + 1) return 1;
			else return 0;
		}
		for (int i = 1; i <= n + 1; ++i) {
			if (visited[i]) continue;
			if (d(pos[i], pos[from]) <= cost) {
				visited[i] = 1;
				q.push({ i,cnt + 1 });
			}
		}
	}
	return 0;
}