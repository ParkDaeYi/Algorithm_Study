#include <iostream>
#include <algorithm>
using namespace std;

int n, m, graph[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; ++i) {
		cin >> a >> b >> c;
		if (!graph[a][b]) graph[a][b] = c;
		else graph[a][b] = min(graph[a][b], c);
	}
	for (int via = 1; via <= n; ++via) 
		for (int from = 1; from <= n; ++from) {
			if (!graph[from][via]) continue;
			for (int to = 1; to <= n; ++to) {
				if (from == to || !graph[via][to]) continue;
				if (!graph[from][to] || graph[from][to] > graph[from][via] + graph[via][to])
					graph[from][to] = graph[from][via] + graph[via][to];
			}
		}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) cout << graph[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}