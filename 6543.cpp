#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define VERTEX 5001
using namespace std;

int n, m, dfsn[VERTEX], cnt, sn[VERTEX], sn_cnt;
bool term[VERTEX];
stack<int> node;
vector<int> graph[VERTEX];
vector<vector<int>> ans;

int dfs(int cur) {
	dfsn[cur] = ++cnt;
	node.push(cur);

	int ret = dfsn[cur];
	for (int nxt : graph[cur]) {
		if (!dfsn[nxt]) ret = min(ret, dfs(nxt));
		else if (!term[nxt]) ret = min(ret, dfsn[nxt]);
	}

	if (ret == dfsn[cur]) {
		vector<int> scc;
		while (1) {
			int t = node.top(); node.pop();
			term[t] = 1;
			scc.push_back(t);
			sn[t] = sn_cnt;
			if (t == cur) break;
		}
		sn_cnt++;
		sort(scc.begin(), scc.end());
		ans.push_back(scc);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (cin >> n) {
		if (!n) return 0;
		cin >> m;
		for (int i = 0;i <= n;++i) graph[i].clear();
		cnt = sn_cnt = 0;
		ans.clear();
		fill(dfsn, dfsn + 1 + n, 0);
		fill(sn, sn + 1 + n, 0);
		fill(term, term + 1 + n, 0);

		for (int i = 0, a, b;i < m;++i) {
			cin >> a >> b;
			graph[a].push_back(b);
		}
		
		for (int i = 1;i <= n;++i)
			if (!dfsn[i]) dfs(i);

		for (int i = 1;i <= n;++i)
			for (int j : graph[i])
				if (sn[i] != sn[j]) ans[sn[i]].clear();

		sort(ans.begin(), ans.end());
		for (int i = 0;i < ans.size();++i) {
			if (ans.empty()) continue;
			for (int j : ans[i]) cout << j << ' ';
		}
		cout << '\n';
	}
}