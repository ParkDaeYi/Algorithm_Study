// DFS
#include <iostream>
#include <vector>
using namespace std;

int n, ans;
vector<int> v[500001];

void dfs(int h, int prv, int dep) {
	bool leaf = 0;
	for (int nxt : v[h]) {
		if (nxt == prv) continue;
		leaf = 1;
		dfs(nxt, h, dep + 1);
	}
	if (!leaf) ans += dep;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, a, b;i < n;++i) {
		cin >> a >> b;
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	dfs(1, 0, 0);
	cout << (ans % 2 ? "Yes" : "No");
	return 0;
}

// BFS
#include <queue>
typedef pair<int, int> pii;

int n, ans;
vector<int> g[500001];
bool visit[500001];

int main_2() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, a, b;i < n;++i) {
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	visit[1] = 1;
	queue<pii> q;
	q.push({ 1,0 });
	while (!q.empty()) {
		int cur = q.front().first, dep = q.front().second, c = 0;
		q.pop();
		for (int nxt : g[cur]) {
			if (visit[nxt]) continue;
			visit[nxt] = 1;
			++c;
			q.push({ nxt,dep + 1 });
		}
		if (!c) ans += dep;
	}
	cout << (ans % 2 ? "Yes" : "No");
	return 0;
}