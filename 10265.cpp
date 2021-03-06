#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define VERTEX 1001
using namespace std;

int n, k, dfsn[VERTEX], cnt, sn[VERTEX], sn_cnt, cycle[VERTEX], max_cycle[VERTEX], min_cycle[VERTEX], ind[VERTEX], idx, dx[VERTEX], dy[VERTEX], dp[VERTEX][VERTEX];
stack<int> node;
vector<int> graph[VERTEX];
vector<int> adj[VERTEX];

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
			cycle[sn_cnt]++;
			if (t == cur) break;
		}
	}
	return ret;
}

void getMaxCycle(int cur) {
	for (int nxt : adj[cur]) {
		max_cycle[cur] += max_cycle[nxt];
		getMaxCycle(nxt);
	}
}

int solve(int cur, int val) {
	if (cur > idx) return 0;
	int& ret = dp[cur][val];
	if (ret != -1) return ret;
	ret = solve(cur + 1, val);
	if (val >= dx[cur]) {
		for (int i = dx[cur]; i <= dy[cur]; ++i) {
			if (i > val) break;
			ret = max(ret, solve(cur + 1, val - i) + i);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		graph[x].push_back(i);
	}
	for (int i = 1; i <= n; ++i) if (!dfsn[i]) dfs(i);

	// 위상정렬
	for (int i = 1; i <= n; ++i)
		for (int j : graph[i]) {
			if (sn[i] == sn[j]) continue;
			adj[sn[i]].push_back(sn[j]); // SCC로 나누어진 그룹 연결
			ind[sn[j]]++; // indegree 카운팅
		}

	// min_cycle : 최소 인원, max_cycle: 최대 인원
	for (int i = 1; i <= sn_cnt; ++i) max_cycle[i] = min_cycle[i] = cycle[i];
	// adj를 통해 각 정점과 관련된 정점을 계산 ( i가 갔을 때 함께 갈 수 있는 최대 인원 )
	for (int i = 1; i <= sn_cnt; ++i) getMaxCycle(i);
	for (int i = 1; i <= sn_cnt; ++i) {
		// indegree가 없는 정점을 기준: indgree가 없다는 SCC 그룹은 독립적임
		if (ind[i]) continue;
		dx[++idx] = min_cycle[i];
		dy[idx] = max_cycle[i];
	}
	fill(&dp[1][0], &dp[n][n + 1], -1);
	cout << solve(1, k);
	return 0;
}