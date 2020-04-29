#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 200
#define MAX_M 402	// 400 : source, 401: dest
using namespace std;

int n, m, c[MAX_M][MAX_M], f[MAX_M][MAX_M], ans, s = MAX_M - 2, e = MAX_M - 1;
vector<int> adj[MAX_M];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0, a; i < n; ++i) {
		cin >> a;
		for (int j = 0, b; j < a; ++j) {
			cin >> b;
			b += MAX_N - 1;
			// i : 소, b : 축사
			c[i][b] = 1;
			adj[i].push_back(b);
			adj[b].push_back(i);
		}
		// s : 시작점
		c[s][i] = 1;
		adj[s].push_back(i);
		adj[i].push_back(s);
	}
	for (int i = MAX_N; i < MAX_N + m; ++i) {
		// i : 축사, e : 도착점
		c[i][e] = 1;
		adj[i].push_back(e);
		adj[e].push_back(i);
	}

	while (1) {
		int prev[MAX_M];
		fill(prev, prev + MAX_M, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty() && prev[e] == -1) {
			int cur = q.front();
			q.pop();
			for (int nxt : adj[cur]) {
				if (c[cur][nxt] > f[cur][nxt] && prev[nxt] == -1) {
					q.push(nxt);
					prev[nxt] = cur;
					if (nxt == e) break;
				}
			}
		}
		if (prev[e] == -1) break;

		for (int i = e; i != s; i = prev[i]) {
			f[prev[i]][i] += 1;
			f[i][prev[i]] -= 1;
		}
		ans += 1;
	}
	cout << ans;
	return 0;
}