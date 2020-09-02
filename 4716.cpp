#include <iostream>
#include <algorithm>
#define N 1000
using namespace std;

struct Query {
	int k, a, b;
	bool operator<(const Query& q) const {
		return abs(a - b) > abs(q.a - q.b);
	}
}q[N];
int n, a, b, ans;

void fa(int i) {
	int t = min(a, q[i].k);
	ans += t * q[i].a;
	a -= t; q[i].k -= t;
}

void fb(int i) {
	int t = min(b, q[i].k);
	ans += t * q[i].b;
	b -= t; q[i].k -= t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (1) {
		cin >> n >> a >> b;
		if (!n) break;
		for (int i = 0; i < n; ++i) cin >> q[i].k >> q[i].a >> q[i].b;
		sort(q, q + n);
		ans = 0;
		// Da 와 Db 의 차이가 큰 순으로 정렬
		// ==>  k 의 값은 한정되어 있기 때문에
		//		Da와 Db 중 작은 값을 우선적으로 갱신하기 위함
		//		둘 중 큰 값을 갱신한다는 것은 a 와 b 중 0이 됬음을 뜻함
		for (int i = 0; i < n; ++i) {
			if (q[i].a < q[i].b) fa(i), fb(i);
			else fb(i), fa(i);
		}
		cout << ans << '\n';
	}
	return 0;
}

// MCMF 풀이
#include <queue>
#include <vector>
#include <memory.h>
#define INF 0x7fffffff
#pragma warning(disable:4996)

int n, a, b;

int MCMF() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> n >> a >> b;
		if (!n && !a && !b) break;
		// S: n + 1, A: n + 2, B: n + 3, E: n + 4
		vector<vector<int>> g(n + 5), c(n + 5, vector<int>(n + 5)), f(n + 5, vector<int>(n + 5)), d(n + 5, vector<int>(n + 5));
		const int S = n + 1, A = n + 2, B = n + 3, E = n + 4;
		g[S].emplace_back(A); g[A].emplace_back(S);
		g[S].emplace_back(B); g[B].emplace_back(S);
		c[S][A] = a;
		c[S][B] = b;
		for (int i = 1; i <= n; ++i) {
			cin >> c[i][E] >> d[A][i] >> d[B][i];
			g[E].emplace_back(i); g[i].emplace_back(E);
			g[i].emplace_back(A); g[A].emplace_back(i);
			g[i].emplace_back(B); g[B].emplace_back(i);
			c[A][i] = c[B][i] = INF;
			d[i][A] = -d[A][i]; d[i][B] = -d[B][i];
		}
		int ans = 0;
		while (1) {
			vector<int> prev(n + 5, -1), dist(n + 5, INF);
			vector<bool> visit(n + 5, 0);
			queue<int> q;
			q.push(S);
			dist[S] = 0; visit[S] = 1;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				visit[cur] = 0;
				for (int nxt : g[cur]) {
					if (c[cur][nxt] > f[cur][nxt] && dist[nxt] > dist[cur] + d[cur][nxt]) {
						dist[nxt] = dist[cur] + d[cur][nxt];
						prev[nxt] = cur;
						if (!visit[nxt]) {
							q.push(nxt);
							visit[nxt] = 1;
						}
					}
				}
			}
			if (prev[E] == -1) break;
			int flow = INF;
			for (int i = E; i != S; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
			for (int i = E; i != S; i = prev[i]) {
				ans += flow * d[prev[i]][i];
				f[prev[i]][i] += flow;
				f[i][prev[i]] -= flow;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}