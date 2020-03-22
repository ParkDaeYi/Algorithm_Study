#include <iostream>
using namespace std;

int graph[101][101], n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0, from, to; i < m; ++i) {
		cin >> from >> to;
		graph[from][to] = 1;
	}
	for (int via = 1; via <= n; ++via) {
		for (int from = 1; from <= n; ++from) {
			if (!graph[from][via]) continue;
			for (int to = 1; to <= n; ++to) {
				if (!graph[via][to] || from == to) continue;
				if (graph[from][via] && graph[via][to]) graph[from][to] = 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		int cnt = n;
		for (int j = 1; j <= n; ++j) {
			if (graph[i][j] || graph[j][i]) --cnt;
		}
		cout << cnt - 1 << '\n';
	}
	return 0;
}