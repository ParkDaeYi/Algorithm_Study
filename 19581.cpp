#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> g[100001];
bool visit[100001];

pii bfs(int s, int x = 0) {
	fill(visit, visit + n + 1, 0);
	visit[s] = 1;
	queue<pii> q;
	q.push({ s,0 });
	pii ret = pii(s, 0);
	while (!q.empty()) {
		int cur = q.front().first, cost = q.front().second;
		q.pop();
		if (x == cur) continue;
		if (ret.second < cost) ret = pii(cur, cost);
		for (pii nxt : g[cur]) {
			if (visit[nxt.first]) continue;
			visit[nxt.first] = 1;
			q.push({ nxt.first,cost + nxt.second });
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, a, b, c;i < n;++i) {
		cin >> a >> b >> c;
		g[a].emplace_back(pii(b, c));
		g[b].emplace_back(pii(a, c));
	}
    // 1 에서 가장 긴 정점
	int a = bfs(1).first;
    // a 에서 가장 긴 정점
	int b = bfs(a).first;
    // a에서 출발 대신 b는 가지 않음
    // b에서 출발 대신 a는 가지 않음
	cout << max(bfs(a, b).second, bfs(b, a).second);
	return 0;
}