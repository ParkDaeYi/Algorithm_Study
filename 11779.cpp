#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define N 1001
#define INF 0x7fffffff
#pragma warning(disable:4996)
using namespace std;
typedef pair<int, int> pii;

int v, e, prv[N], dist[N], S, E;
vector<pii> g[N];

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	for (int i = 0, a, b, c;i < e;++i) {
		cin >> a >> b >> c;
		g[a].emplace_back(pii(c, b));
	}
	cin >> S >> E;
	priority_queue<pii, vector<pii>, less<pii>> pq;
	pq.push({ 0,S });
	fill(dist, dist + ++v, INF);
	dist[S] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second, cost = -pq.top().first;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (pii& i : g[cur]) {
			int nxt = i.second, ncost = i.first;
			if (dist[nxt] > dist[cur] + ncost) {
				prv[nxt] = cur;
				dist[nxt] = dist[cur] + ncost;
				pq.push({ -dist[nxt],nxt });
			}
		}
	}
	cout << dist[E] << '\n';
	stack<int> ans;
	while (E) {
		ans.push(E);
		E = prv[E];
	}
	cout << ans.size() << '\n';
	while (!ans.empty()) cout << ans.top() << ' ', ans.pop();
	return 0;
}