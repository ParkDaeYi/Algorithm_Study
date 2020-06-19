#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define VERTEX 20002
using namespace std;

int n, m, cnt, dfsn[VERTEX], sn_cnt, sn[VERTEX];
stack<int> node;
vector<int> graph[VERTEX];

inline int oppo(int x) { return x % 2 ? x - 1 : x + 1; }

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

	cin >> n >> m;
	for (int i = 0, a, b; i < m; ++i) {
		cin >> a >> b;
		a = a < 0 ? -(a + 1) * 2 : a * 2 - 1;
		b = b < 0 ? -(b + 1) * 2 : b * 2 - 1;

		// (X V Y) == ㄱX->Y == ㄱY->X
		graph[oppo(a)].push_back(b);
		graph[oppo(b)].push_back(a);
	}

	for (int i = 0; i < n + n; ++i) if (!dfsn[i]) dfs(i);

	bool flag = 0;
	for (int i = 0; i < n; ++i) {
		if (sn[i * 2] == sn[i * 2 + 1]) {
			flag = 1;
			break;
		}
	}

	cout << (flag ? 0 : 1);
	return 0;
}