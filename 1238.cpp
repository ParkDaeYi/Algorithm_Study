#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#define MAX 1e9+1
using namespace std;
typedef pair<int, int> pii;

vector<pii> graph1[1000], graph2[1000];
int n, m, x, dist[1000], res[1000], ans;

void dij(vector<pii>[]);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> x;
	for (int i = 0, from, to, cost; i < m; ++i) {
		cin >> from >> to >> cost;
		graph1[from - 1].push_back({ cost,to - 1 });
		graph2[to - 1].push_back({ cost,from - 1 });
	}
	dij(graph1);
	dij(graph2);
	for (int i = 0; i < n; ++i) ans = max(ans, res[i]);
	cout << ans;
	return 0;
}

void dij(vector<pii> graph[]) {
	fill(dist, dist + n, MAX); dist[x - 1] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,x - 1 });
	while (!pq.empty()) {
		int cur = pq.top().second, cost = pq.top().first;
		pq.pop();
		if (cost > dist[cur]) continue;
		for (pii next : graph[cur]) {
			if (dist[next.second] > dist[cur] + next.first) {
				dist[next.second] = dist[cur] + next.first;
				pq.push({ dist[next.second],next.second });
			}
		}
	}
	for (int i = 0; i < n; ++i) res[i] += dist[i];
	return;
}