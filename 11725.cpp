// 스택
#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> pii;

int n, p[100001];
stack<pii> st[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	p[1] = 1;
	for (int i = 1, a, b;i < n;++i) {
		cin >> a >> b;
		if (p[a]) p[b] = a;
		else if (p[b]) p[a] = b;
		else st[0].push({ a,b });
	}

	int itr = 0;
	while (st[0].size() || st[1].size()) {
		int a = st[itr].top().first, b = st[itr].top().second;
		st[itr].pop();
		if (p[a]) p[b] = a;
		else if (p[b]) p[a] = b;
		else st[1 - itr].push({ a,b });
		if (st[itr].empty()) itr = 1 - itr;
	}

	for (int i = 2;i <= n;++i) cout << p[i] << '\n';

	return 0;
}

// 그래프
#include <vector>

int n, p[100001];
vector<int> g[100001];

void dfs(int here, int prv = 0) {
	p[here] = prv;
	for (int nxt : g[here]) if (nxt ^ prv) dfs(nxt, here);
}

int main_2() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, a, b;i < n;++i) {
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dfs(1);
	for (int i = 2;i <= n;++i) cout << p[i] << '\n';

	return 0;
}