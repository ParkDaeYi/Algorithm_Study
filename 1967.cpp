#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, ans, y;
vector<pii> g[10001];

void dfs(int prev, int here, int dist) {
	if (ans < dist) {
		y = here;
		ans = dist;
	}
	for (pii n : g[here]) {
		if (n.first ^ prev) dfs(here, n.first, dist + n.second);		
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, a, b, c;i < n - 1;++i) {
		cin >> a >> b >> c;
		g[a].emplace_back(pii(b, c));
		g[b].emplace_back(pii(a, c));
	}
	// 임의에 루트에서 가장 거리가 먼 정점을 구함 => y
	dfs(0, 1, 0);
	// y에서 가장 거리가 먼 정점까지의 거리를 구함
	dfs(0, y, 0);
	cout << ans;
	return 0;
}