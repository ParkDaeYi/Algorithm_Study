#include <iostream>
using namespace std;

int graph[401][401], n, k, s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0, before, after; i < k; ++i) {
		cin >> before >> after;
		graph[before][after] = -1;
		graph[after][before] = 1;
	}
	for (int via = 1; via <= n; ++via) {
		for (int from = 1; from <= n; ++from) {
			if (!graph[from][via]) continue;
			for (int to = 1; to <= n; ++to) {
				if (!graph[via][to] || from == to) continue;
				if (graph[from][via] == 1 && graph[via][to] == 1) graph[from][to] = 1;
				if (graph[from][via] == -1 && graph[via][to] == -1) graph[from][to] = -1;
			}
		}
	}
	cin >> s;
	for (int i = 0, a, b; i < s; ++i) {
		cin >> a >> b;
		cout << graph[a][b] << '\n';
	}
	return 0;
}