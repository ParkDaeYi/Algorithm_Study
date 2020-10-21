// 1967_트리의 지름과 같은 로직임
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n, ans, y;
vector<pii> g[100001];

void dfs(int cur, int prv, int dist) {
	bool leaf = 0;
	for (pii nxt : g[cur]) {
		if (nxt.first == prv) continue;
		leaf = 1;
		dfs(nxt.first, cur, dist + nxt.second);
	}
	if (!leaf && ans < dist) ans = dist, y = cur;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, a, b, c;i < n;++i) {
		cin >> a;
		while (1) {
			cin >> b;
			if (b == -1) break;
			cin >> c;
			g[a].emplace_back(pii(b, c));
		}
	}
	dfs(1, 0, 0);
	dfs(y, 0, 0);
	cout << ans;
	return 0;
}