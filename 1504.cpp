#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#define INF 1e9
#define MAX 801
using namespace std;
typedef pair<int, int> pii;

int n, e, node1, node2, ans;
vector<pii> graph[MAX];

vector<int> dij(int);
inline int min_int(int a, int b) {
	return a > b ? b : a;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> e;
	for (int i = 0, from, to, cost; i < e; ++i) {
		cin >> from >> to >> cost;
		graph[from].push_back({ cost,to });
		graph[to].push_back({ cost,from });
	}
	cin >> node1 >> node2;
	vector<int> t1 = dij(1);
	vector<int> t2 = dij(node1);
	vector<int> t3 = dij(node2);
	ans = min_int(t1[node1] + t2[node2] + t3[n], t1[node2] + t3[node1] + t2[n]);
	if (ans >= INF || ans < 0) cout << -1;
	else cout << ans;
	return 0;
}

vector<int> dij(int start) {
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = pq.top().first, cur = pq.top().second;
		pq.pop();
		if (cost > dist[cur]) continue;
		for (pii next : graph[cur]) {
			if (dist[next.second] > dist[cur] + next.first) {
				dist[next.second] = dist[cur] + next.first;
				pq.push(next);
			}
		}
	}
	return dist;
}