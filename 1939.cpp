#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, m, a, b, c, max_c, from, to;
bool visited[10001];
vector<pii> graph[10001];

bool bfs(int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
		max_c = max_c > c ? max_c : c;
	}
	cin >> from >> to;
	int left = 1, right = max_c, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		fill(visited + 1, visited + 1 + n, 0);
		if (bfs(mid)) left = mid + 1;
		else right = mid - 1;
	}
	cout << right;
	return 0;
}
bool bfs(int cost) {
	queue<int> q;
	q.push(from);
	visited[from] = 1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == to) return 1;
		for (pii next : graph[here]) {
			if (visited[next.first]) continue;
			if (cost <= next.second) {
				q.push(next.first);
				visited[next.first] = 1;
			}
		}
	}
	return false;
}