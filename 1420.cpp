#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
//#include <unordered_map>
#include <map>
#include <cmath>
#define MAX_N 20002
#define INF 1e9
using namespace std;
typedef pair<int, int> pii;

char arr[101][101];
int n, m, S = -1, E = -1, idx = 0, sx, sy, tx, ty, ans;
//unordered_map<pii, int> c, f; 왜 안되지...
map<pii, int> c, f;
vector<int> adj[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 'K') {
				S = idx + 1;
				sx = j, sy = i;
			}
			else if (arr[i][j] == 'H') {
				E = idx;
				tx = j, ty = i;
			}
			idx += 2;
		}
	}

	//예외 처리
	if ((n == 1 && m == 1) || S == -1 || E == -1 || abs(sx - tx) + abs(sy - ty) == 1) {
		cout << -1;
		return 0;
	}

	// 정점 분할
	for (int i = 0; i < n * m; ++i) {
		int to = i * 2, from = i * 2 + 1;
		c[{to, from}] = 1;
		c[{from, to}] = 0;
		adj[to].push_back(from);
		adj[from].push_back(to);
	}

	for (int i = 0, u = 0; i < n; ++i) {
		for (int j = 0, v; j < m; ++j) {
			// 좌 우 연결
			if (j + 1 < m && arr[i][j] != '#' && arr[i][j + 1] != '#') {
				v = u + 2;
				c[{u + 1, v}] = INF;
				c[{v, u + 1}] = 0;
				c[{v + 1, u}] = INF;
				c[{u, v + 1}] = 0;

				adj[u + 1].push_back(v);
				adj[v].push_back(u + 1);
				adj[v + 1].push_back(u);
				adj[u].push_back(v + 1);
			}
			// 상 하 연결
			if (i + 1 < n && arr[i][j] != '#' && arr[i + 1][j] != '#') {
				v = m * 2 + u;
				c[{u + 1, v}] = INF;
				c[{v, u + 1}] = 0;
				c[{v + 1, u}] = INF;
				c[{u, v + 1}] = 0;

				adj[u + 1].push_back(v);
				adj[v].push_back(u + 1);
				adj[v + 1].push_back(u);
				adj[u].push_back(v + 1);
			}
			u += 2;
		}
	}

	while (1) {
		int prev[MAX_N];
		fill(prev, prev + n * m * 2, -1);
		queue<int> q;
		q.push(S);
		while (!q.empty() && prev[E] == -1) {
			int cur = q.front(); q.pop();
			for (int nxt : adj[cur]) {
				if (c[{cur, nxt}] > f[{cur, nxt}] && prev[nxt] == -1) {
					prev[nxt] = cur;
					q.push(nxt);
					if (nxt == E) break;
				}
			}
		}
		if (prev[E] == -1) break;
		for (int i = E; i != S; i = prev[i]) {
			f[{prev[i], i}] += 1;
			f[{i, prev[i]}] -= 1;
		}
		ans += 1;
	}
	cout << ans;
	return 0;
}