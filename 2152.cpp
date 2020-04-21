#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>
#define VERTEX 10001
using namespace std;
typedef pair<int, int> pii;

int n, m, s, t, cnt, dfsn[VERTEX], sn[VERTEX], sn_cnt, visit[VERTEX];
bool term[VERTEX];
stack<int> node;
vector<int> graph[VERTEX];
vector<vector<int>> res;
unordered_set<int> outdegree[VERTEX];

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
			scc.push_back(t);
			term[t] = 1;
			if (t == cur) break;
		}
		res.push_back(scc);
		sn_cnt++;
	}

	return ret;
}

int solve(int s, int e) {
	queue<pii> q;
	q.push(pii(s, res[s].size()));
	int ans = 0;
	while (!q.empty()) {
		int cur = q.front().first, sum = q.front().second;
		q.pop();
		if (cur == e) ans = max(ans, sum);
		else {
			for (int itr : outdegree[cur]) {
				if (visit[itr] < sum + res[itr].size()) {
					visit[itr] = sum + res[itr].size();
					q.push(pii(itr, visit[itr]));
				}
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> s >> t;
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= n; ++i)
		if (!dfsn[i]) dfs(i);

	for (int i = 1; i <= n; ++i)
		for (int j : graph[i]) {
			if (sn[i] == sn[j]) continue;
			outdegree[sn[i]].insert(sn[j]);
		}

	s = sn[s];
	t = sn[t];
	cout << solve(s, t);
	return 0;
}