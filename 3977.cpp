#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define VERTEX 100001
using namespace std;

int t, n, m, cnt, dfsn[VERTEX], sn[VERTEX], sn_cnt, indegree[VERTEX];
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
			sn[t] = sn_cnt;
			term[t] = 1;
			scc.push_back(t);
			if (t == cur) break;
		}
		sn_cnt++;
		ans.push_back(scc);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0;i < n;++i) graph[i].clear();
		fill(dfsn, dfsn + n, 0);
		fill(sn, sn + n, 0);
		fill(term, term + n, 0);
		fill(indegree, indegree + n, 0);
		cnt = sn_cnt = 0;
		ans.clear();

		for (int i = 0, a, b;i < m;++i) {
			cin >> a >> b;
			graph[a].push_back(b);
		}
		for (int i = 0;i < n;++i)
			if (!dfsn[i]) dfs(i);
		int idx = -1;
		bool flag = 0;
		for (int i = 0;i < n;++i)
			for (int j : graph[i])
				if (sn[i] != sn[j]) indegree[sn[j]]++;
		for(int i=0;i<ans.size();++i)
			if (!indegree[i]) {
				if (idx == -1) idx = i;
				else {
					flag = 1;
					break;
				}
			}

		if (flag) cout << "Confused\n";
		else {
			sort(ans[idx].begin(), ans[idx].end());
			for (int p : ans[idx]) cout << p << '\n';
		}
		cout << '\n';
	}
	return 0;
}