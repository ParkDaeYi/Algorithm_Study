#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define VERTEX 20002
using namespace std;

int n, m, cnt, dfsn[VERTEX], sn_cnt, sn[VERTEX];
vector<int> graph[VERTEX];
stack<int> node;

int neg(int x) { return x > n ? x - n : x + n; }

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
		if (a < 0) a = -a + n;
		if (b < 0) b = -b + n;

		// (X V Y) == ㄱX->Y == ㄱY->X
		graph[neg(a)].push_back(b);
		graph[neg(b)].push_back(a);
	}
	for (int i = 1; i <= n * 2; ++i) if (!dfsn[i]) dfs(i);
	
	bool flag = 0;
	for (int i = 1; i <= n; ++i) {
		if (sn[i] == sn[neg(i)]) {
			flag = 1;
			break;
		}
	}

	if (flag) cout << 0 << '\n';
	else {
		cout << 1 << '\n';
		// X -> Y 경우 X가 거짓 => Y는 참 or 거짓, X가 참 => Y는 무조건 참
		// X -> Y가 되는 경우는 (ㄱX V Y)임. 위의 조건이 만족하면 이 식은 항상 참
		// sn[i] < sn[neg(i)] 로 한 이유를 간단히 설명하자면
		// (X V X)인 경우 ㄱX -> X 형태가 됨.
		// 이 식을 SCC를 통해 번호를 메기면 ㄱX보다 X가 SCC 특성상 더 작은 번호를 갖게 됨
		// (X V X)가 참이 되려면 당연히 X가 참이여야함
		for (int i = 1; i <= n; ++i) cout << (sn[i] < sn[neg(i)]) << ' ';
		cout << '\n';
	}
	return 0;
}