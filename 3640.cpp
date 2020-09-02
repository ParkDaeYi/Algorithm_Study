#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x7fffffff
#pragma warning(disable:4996)
using namespace std;

int v, e;
vector<vector<int>> g, c, f, d;

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while ((cin >> v >> e)) {
		g.resize(v * 2 + 1);
		// 두 전함은 항상 겹치지 않는 뱃길을 택해야 하며, 출발과 목적지를 제외하고 같은 중간 지점이나 같은 뱃길을 지나면 안 된다.
		// ==> 정점 분할을 통해 겹치지 않도록 함
		c = f = d = vector<vector<int>>(v * 2 + 1, vector<int>(v * 2 + 1));
		for (int i = 1; i <= v; ++i) {
			if (i == 1 || i == v) c[i][i + v] = 2;
			else c[i][i + v] = 1;
			g[i].emplace_back(i + v);
			g[i + v].emplace_back(i);
		}
		for (int i = 0, x, y, z; i < e; ++i) {
			cin >> x >> y >> z;
			c[x + v][y] = 1;
			d[x + v][y] = z; d[y][x + v] = -z;
			g[x + v].emplace_back(y);
			g[y].emplace_back(x + v);
		}
		int ans = 0;
		while (1) {
			vector<int> prv(v * 2 + 1, -1), dist(v * 2 + 1, INF);
			vector<bool> visit(v * 2 + 1, 0);
			queue<int> q;
			q.push(1);
			dist[1] = 0;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				visit[cur] = 0;
				for (int nxt : g[cur]) {
					if (c[cur][nxt] > f[cur][nxt] && dist[nxt] > dist[cur] + d[cur][nxt]) {
						dist[nxt] = dist[cur] + d[cur][nxt];
						prv[nxt] = cur;
						if (!visit[nxt]) {
							q.push(nxt);
							visit[nxt] = 1;
						}
					}
				}
			}
			if (prv[v * 2] == -1) break;
			int flow = INF;
			for (int i = v * 2; i != 1; i = prv[i]) flow = min(flow, c[prv[i]][i] - f[prv[i]][i]);
			for (int i = v * 2; i != 1; i = prv[i]) {
				ans += flow * d[prv[i]][i];
				f[prv[i]][i] += flow;
				f[i][prv[i]] -= flow;
			}
		}
		cout << ans << '\n';
		g.clear();
	}
	return 0;
}