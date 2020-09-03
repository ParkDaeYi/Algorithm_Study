#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#define N 1001
#pragma warning(disable:4996)
using namespace std;
typedef pair<int, int> pii;

int v, e, k;
priority_queue<int, vector<int>, less<int>> dist[N];
vector<pii> g[N];

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e >> k;
	for (int i = 0, a, b, c;i < e;++i) {
		cin >> a >> b >> c;
		g[a].emplace_back(pii(c, b));
	}
	priority_queue<pii, vector<pii>, less<pii>> pq;
	pq.push({ 0,1 });
	dist[1].push(0);
	while (!pq.empty()) {
		int cost = -pq.top().first, cur = pq.top().second;
		pq.pop();
		if (dist[cur].top() < cost) continue;
		for (pii p : g[cur]) {
			int nxt = p.second, ncost = p.first + cost;
			if (dist[nxt].size() < k) {
				dist[nxt].push(ncost);
				pq.push({ -ncost,nxt });
			}
			else if (dist[nxt].top() > ncost) {
				dist[nxt].pop();
				dist[nxt].push(ncost);
				pq.push({ -ncost,nxt });
			}
		}
	}
	for (int i = 1;i <= v;++i) cout << (dist[i].size() ^ k ? -1 : dist[i].top()) << '\n';
	return 0;
}