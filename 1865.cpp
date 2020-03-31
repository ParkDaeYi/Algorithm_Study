#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

int t, n, m, w, s, e, dist[501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m >> w;
		fill(dist, dist + n + 1, INF);
		vector<pii> graph[501];
		for (int i = 0; i < m; ++i) {
			int from, to, cost;
			cin >> from >> to >> cost;
			graph[from].push_back(make_pair(to, cost));
			graph[to].push_back(make_pair(from, cost));
		}
		for (int i = 0; i < w; ++i) {
			int from, to, cost;
			cin >> from >> to >> cost;
			graph[from].push_back(make_pair(to, -cost));
		}
		dist[1] = 0;
		bool cycle = 0;
		int cnt = 0;
		while (!cycle && cnt != n) {
			cycle = 1;
			cnt++;
			for (int i = 1;i <= n;++i) {
				for (pii nxt : graph[i]) {
					if (dist[nxt.first] > dist[i] + nxt.second) {
						dist[nxt.first] = dist[i] + nxt.second;
						cycle = 0;
					}
				}
			}
		}
		cout << (cnt == n ? "YES" : "NO") << '\n';
	}
	return 0;
}