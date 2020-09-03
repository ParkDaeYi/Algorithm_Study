#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 100
#define M 2*(N+1)
#pragma warning(disable:4996)
using namespace std;

int n, m, c[M][M], f[M][M];
vector<int> g[M];

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	const int S = n + m, E = S + 1;
	for (int i = m; i < S; ++i) {
		cin >> c[i][E];
		g[i].emplace_back(E);
		g[E].emplace_back(i);
	}
	for (int i = 0; i < m; ++i) {
		cin >> c[S][i];
		g[S].emplace_back(i);
		g[i].emplace_back(S);
	}
	for (int i = 0; i < m; ++i) {
		for (int j = m; j < S; ++j) {
			cin >> c[i][j];
			if (!c[i][j]) continue;
			g[i].emplace_back(j);
			g[j].emplace_back(i);
		}
	}
	int ans = 0;
	while (1) {
		int prev[M];
		fill(prev, prev + M, -1);
		queue<int> q;
		q.push(S);
		while (!q.empty() && prev[E] == -1) {
			int cur = q.front(); q.pop();
			for (int nxt : g[cur]) {
				if (c[cur][nxt] > f[cur][nxt] && prev[nxt] == -1) {
					q.push(nxt);
					prev[nxt] = cur;
					if (nxt == E) break;
				}
			}
		}
		if (prev[E] == -1) break;
		int flow = 1e9;
		for (int i = E; i ^ S; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for (int i = E; i ^ S; i = prev[i]) {
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
		ans += flow;
	}
	cout << ans;
	return 0;
}