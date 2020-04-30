#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX_N 100001
using namespace std;

int n, m, cnt, dfsn[MAX_N], sn_cnt, sn[MAX_N], ind[MAX_N], ans;
stack<int> node;
vector<int> adj[MAX_N];

int dfs(int cur) {
	dfsn[cur] = ++cnt;
	node.push(cur);

	int ret = dfsn[cur];
	for (int nxt : adj[cur]) {
		if (!dfsn[nxt]) ret = min(ret, dfs(nxt));
		else if (!sn[nxt]) ret = min(ret, dfsn[nxt]);
	}

	if (ret == dfsn[cur]) {
		sn_cnt++;
		while (1) {
			int t = node.top(); node.pop();
			sn[t] = sn_cnt;
			if (t == cur) break;
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0, a, b;i < m;++i) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for (int i = 0;i < n;++i)
		if (!dfsn[i]) dfs(i);

	for (int i = 0;i < n;++i) 
		for (int j : adj[i]) {
			if (sn[i] == sn[j]) continue;
			ind[sn[j]]++;
		}
	for (int i = 1;i <= sn_cnt;++i)
		if (!ind[i]) ans++;
	cout << ans;
	return 0;
}