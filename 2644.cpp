#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph[101];
int n, q1, q2, m, cache[101];

int bfs();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q1 >> q2 >> m;
	for (int i = 0, from, to; i < m; ++i) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	cout << bfs();
	return 0;
}

int bfs() {
	queue<int> q;
	q.push(q1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == q2) return cache[cur];
		for (int next : graph[cur]) {
			if (cache[next]) continue;
			q.push(next);
			cache[next] = cache[cur] + 1;
		}
	}
	return -1;
}