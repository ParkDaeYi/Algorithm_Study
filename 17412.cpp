#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 401
#define INF 1e9
using namespace std;

int n, p, c[MAX_N][MAX_N], f[MAX_N][MAX_N], ans, source = 1, sink = 2;
vector<int> adj[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> p;
	for (int i = 0, a, b; i < p; ++i) {
		cin >> a >> b;
		c[a][b] = 1;
		c[b][a] = 0;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	while (1) {
		int prev[MAX_N];
		fill(prev, prev + MAX_N, -1);
		queue<int> q;
		q.push(source);
		while (!q.empty() && prev[sink] == -1) {
			int cur = q.front();
			q.pop();
			for (int& nxt : adj[cur]) {
				if (c[cur][nxt] > f[cur][nxt] && prev[nxt] == -1) {
					prev[nxt] = cur;
					q.push(nxt);
					if (nxt == sink) break;
				}
			}
		}
		if (prev[sink] == -1) break;

		int flow = INF;
		for (int i = sink; i != source; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for (int i = sink; i != source; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		ans += flow;
	}
	cout << ans;

	return 0;
}