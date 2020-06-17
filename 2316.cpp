#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_N 801
#define INF 1e9
using namespace std;

int n, p, c[MAX_N][MAX_N], f[MAX_N][MAX_N], ans;
vector<int> adj[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> p;
	for (int i = 3; i <= n; ++i) {
		int u = i, v = i + n;
		c[u][v] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0, a, b; i < p; ++i) {
		cin >> a >> b;
		c[a + n][b] = c[b + n][a] = 1;
		adj[a + n].push_back(b);
		adj[b].push_back(a + n);
		adj[b + n].push_back(a);
		adj[a].push_back(b + n);
	}
	int S = 1 + n, E = 2;
	while (1) {
		int prev[MAX_N];
		fill(prev, prev + MAX_N, -1);
		queue<int> q;
		q.push(S);
		while (!q.empty() && prev[E] == -1) {
			int cur = q.front(); q.pop();
			for (int nxt : adj[cur]) {
				if (c[cur][nxt] > f[cur][nxt] && prev[nxt] == -1) {
					prev[nxt] = cur;
					q.push(nxt);
					if (nxt == E) break;
				}
			}
		}
		if (prev[E] == -1) break;

		int flow = INF;
		for (int i = E; i != S; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for (int i = E; i != S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		ans += flow;
	}
	cout << ans;
	return 0;
}