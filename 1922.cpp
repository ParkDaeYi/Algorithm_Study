#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 1001
using namespace std;
typedef pair<int, int> pii;

int n, m, ans, cnt;
vector<pii> graph[MAX_N];
bool visit[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0, a, b, c;i < m;++i) {
		cin >> a >> b >> c;
		graph[a].push_back(pii(c, b));
		graph[b].push_back(pii(c, a));
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, 1));
	while (!pq.empty()) {
		int cur = pq.top().second, cost = pq.top().first;
		pq.pop();
		if (visit[cur]) continue;
		visit[cur] = 1;
		ans += cost;
		if (++cnt == n) break;
		for (pii p : graph[cur]) {
			if (visit[p.second]) continue;
			pq.push(p);
		}
	}
	cout << ans;
	return 0;
}