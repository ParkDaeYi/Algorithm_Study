#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define VERTEX 52
#define INF 1e9
using namespace std;

int n, c[VERTEX][VERTEX], f[VERTEX][VERTEX], ans;
vector<int> adj[VERTEX];

inline int ctoi(char x) {
	if (x <= 'Z') return x - 'A';
	return x - 'a' + 26;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, w; i < n; ++i) {
		char u, v;
		cin >> u >> v >> w;
		u = ctoi(u), v = ctoi(v);
		c[u][v] = c[v][u] += w;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int s = ctoi('A'), e = ctoi('Z');
	while (1) {
		int prev[VERTEX];
		fill(prev, prev + VERTEX, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty() && prev[e] == -1) {
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur]) {
				if (c[cur][nxt] > f[cur][nxt] && prev[nxt] == -1) {
					prev[nxt] = cur;
					q.push(nxt);
					if (nxt == e) break;
				}
			}
		}
		if (prev[e] == -1) break;
		
		int flow = INF;
		for (int i = e; i != s; i = prev[i])
			flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for (int i = e; i != s; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		ans += flow;
	}
	cout << ans;
	return 0;
}