#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define N 100001
#define INF 0x7fffffffffffffff
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

int n, m;
ll ans = -INF, d, e, h[N];
vector<pli> g[N];

vector<ll> dij(int s) {
	vector<ll> dist(n, INF);
	dist[s] = 0;
	priority_queue<pli, vector<pli>, less<pli>> pq;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int cur = pq.top().second, cost = -pq.top().first;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (pli& i : g[cur]) {
			int nxt = i.second; ll ncost = i.first;
			if (h[cur]<h[nxt] && dist[nxt]>dist[cur] + ncost) {
				dist[nxt] = dist[cur] + ncost;
				pq.push({ -dist[nxt],nxt });
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> d >> e;
	++n;
	for (int i = 1;i < n;++i) cin >> h[i];
	for (int i = 0, a, b, c;i < m;++i) {
		cin >> a >> b >> c;
		g[a].emplace_back(pli(c, b));
		g[b].emplace_back(pli(c, a));
	}
	// 집에서 출발하거나 고대에서 출발하거나
	// 더 높아지는 경로로 이동 하면 됨
	// 집에서 출발
	vector<ll> sdist = dij(1);
	// 고대에서 출발
	vector<ll> edist = dij(n - 1);
	for (int i = 2;i < n - 1;++i) {
		if (sdist[i] == INF || edist[i] == INF) continue;	// 경로가 없으면 continue
		ans = max(ans, e * h[i] - (sdist[i] + edist[i]) * d);
	}
	if (ans == -INF) cout << "Impossible";
	else cout << ans;
	return 0;
}