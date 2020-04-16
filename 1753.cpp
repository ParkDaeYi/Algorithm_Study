#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define VERTEX 20001
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

int v, e, k, dist[VERTEX];
bool visit[VERTEX];
vector<pii> graph[VERTEX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e >> k;
	for (int i = 0, a, b, c; i < e; ++i) {
		cin >> a >> b >> c;
		graph[a].push_back(pii(c, b));
	}
	fill(dist, dist + v + 1, INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, k));
	dist[k] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first, cur = pq.top().second;
		pq.pop();
		if (visit[cur]) continue;
		visit[cur] = 1;
		dist[cur] = cost;
		for (pii& nxt : graph[cur]) {
			if (visit[nxt.second]) continue;
			nxt.first += cost;
			pq.push(nxt);
		}
	}
	for (int i = 1; i <= v; ++i) {
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
	return 0;
}