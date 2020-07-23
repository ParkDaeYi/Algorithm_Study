#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int indegree[1001], cost[1001], t, n, m, ans[1001], w;
vector<int> graph[1001];

void main_1() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> cost[i];
			indegree[i] = ans[i] = 0;
		}
		for (int i = 0; i < m; ++i) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);	// 그래프 연결
			++indegree[to];	// 들어오는 간선 추가
		}
		cin >> w;

		queue<int> q;
		// 시작 지점을 찾음 (하나 이상일 수도 있음)
		for (int i = 1; i <= n; ++i) {
			if (!indegree[i]) {
				q.push(i);
				ans[i] = cost[i];
			}
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == w) break;

			for (int next : graph[cur]) {
				--indegree[next];

				if (ans[next] < ans[cur] + cost[next]) ans[next] = ans[cur] + cost[next];

				// indegree[next]가 0이 되어야 ans[next] 값이 확실하게 정해져 있음
				if (!indegree[next]) q.push(next);
			}
		}

		cout << ans[w] << '\n';
		for (int i = 1; i <= n; ++i) graph[i].clear();
	}

}

int t, n, k, w;
int cost[1001], dp[1001];
vector<int> graph[1001];

// dp와 재귀를 사용하여 w부터 시작
int solve_2(int cur) {
	if (dp[cur] != -1) return dp[cur];
	int ans = 0;
	for (int nxt : graph[cur]) {
		ans = max(ans, solve_2(nxt));
	}
	return dp[cur] = ans + cost[cur];
}

void main_2() {

	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; ++i) cin >> cost[i], dp[i] = -1;
		for (int i = 0, x, y; i < k; ++i) {
			cin >> x >> y;
			graph[y].push_back(x);	// w부터 시작할 것이므로 반대로 연결
		}

		cin >> w;
		cout << solve_2(w) << '\n';
		for (int i = 1; i <= n; ++i) graph[i].clear();
	}

}