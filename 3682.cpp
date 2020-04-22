#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_set>
#define VERTEX 20001
using namespace std;

int t, n, m, cnt, dfsn[VERTEX], sn[VERTEX], sn_cnt, ind[VERTEX], outd[VERTEX], in_cnt, out_cnt;
stack<int> node;
vector<int> graph[VERTEX];
unordered_set<int> adj[VERTEX];

int dfs(int cur) {
	dfsn[cur] = ++cnt;
	node.push(cur);

	int ret = dfsn[cur];
	for (int nxt : graph[cur]) {
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

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) graph[i].clear();
		cnt = sn_cnt = in_cnt = out_cnt = 0;
		fill(dfsn, dfsn + n, 0);
		fill(sn, sn + n, 0);

		for (int i = 0, a, b; i < m; ++i) {
			cin >> a >> b;
			graph[a - 1].push_back(b - 1);
		}

		for (int i = 0; i < n; ++i)
			if (!dfsn[i]) dfs(i);

		for (int i = 0; i < n; ++i) 
			for (int j : graph[i]) {
				if (sn[i] == sn[j]) continue;
				adj[sn[i]].insert(sn[j]);
			}
		for (int i = 1; i <= sn_cnt; ++i) 
			for (int j : adj[i]) {
				ind[j]++;
				outd[i]++;
			}
		// 모든 정점이 SCC로 이루어져 있을 경우
		// in_cnt, out_cnt 의 값은 1이 되므로 예외 처리를 해주어야함.
		if (sn_cnt == 1) cout << 0 << '\n';
		else {
			for (int i = 1; i <= sn_cnt; ++i) {
				in_cnt += !ind[i];
				out_cnt += !outd[i];
			}
			cout << max(in_cnt, out_cnt) << '\n';
		}
		for (int i = 1; i <= sn_cnt; ++i) adj[i].clear();
		fill(ind, ind + sn_cnt + 1 , 0);
		fill(outd, outd + sn_cnt + 1 , 0);
	}
	return 0;
}