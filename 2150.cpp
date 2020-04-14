#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX_V 10010
using namespace std;

int v, e, cnt, dfsn[MAX_V];
vector<int> graph[MAX_V];
bool term[MAX_V];	// SCC 분리가 끝난 정점만 true
stack<int> s;
vector<vector<int>> ans;

// 자신의 결과값을 리턴하는 DFS 함수
int dfs(int cur) {
	dfsn[cur] = ++cnt; // dfsn 결정 (탐색 순서 넘버링)
	s.push(cur); //스택에 자신을 push

	// 자신의 dfsn, 자식들의 결과나 dfsn 중 가장 작은 번호를 ret에 저장
	int ret = dfsn[cur];
	for (int nxt : graph[cur]) {
		// 아직 방문하지 않았을 경우
		if (!dfsn[nxt]) ret = min(ret, dfs(nxt));
		// 방문은 했으나 아직 SCC로 추출되지 않았을 경우
		else if (!term[nxt]) ret = min(ret, dfsn[nxt]);
	}

	// 자신
	// 자신의 자손들이 도달 가능한 제일 높은 정점이 자신일 경우 SCC 추출
	if (ret == dfsn[cur]) {
		vector<int> scc;
		// 스택에서 자신이 나올 때까지 pop
		while (1) {
			int t = s.top(); s.pop();
			scc.push_back(t);
			term[t] = 1;
			if (t == cur) break;
		}
		sort(scc.begin(), scc.end());
		// SCC 추출
		ans.push_back(scc);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	for (int i = 0, a, b;i < e;++i) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i = 1;i <= v;++i) {
		if (!dfsn[i]) dfs(i);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (vector<int>& v : ans) {
		for (int p : v) cout << p << ' ';
		cout << "-1\n";
	}
	return 0;
}