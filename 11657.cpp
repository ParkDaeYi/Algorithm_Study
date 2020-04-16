#include <iostream>
#include <vector>
#define MAX_N 501
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

int dist[MAX_N], n, m;
bool visit[MAX_N];
vector<pii> graph[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back(pii(b, c));
	}
	fill(dist, dist + n + 1, INF);
	dist[1] = 0;
	bool cycle = 0;
	int cnt = 0;
	while (!cycle && cnt != n) {
		cycle = 1;
		cnt++;
		for (int i = 1; i <= n; ++i) {
			if (dist[i] == INF) continue;
			for (pii nxt : graph[i]) {
				if (dist[nxt.first] > dist[i] + nxt.second) {
					dist[nxt.first] = dist[i] + nxt.second;
					if (cnt == n) {
						cout << -1;
						return 0;
					}
					cycle = 0;
				}
			}
		}
	}
	for (int i = 2; i <= n; ++i) {
		if (dist[i] == INF) cout << "-1\n";
		else cout << dist[i] << '\n';
	}
	return 0;
}