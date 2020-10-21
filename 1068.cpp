// 이 문제는 DFS말고 BFS로 푸는게 정신건강에 좋다
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, r, d, ans;
vector<int> g[51];
bool visit[51];

void bfs() {
	if (r == d) return;
	visit[r] = 1;
	queue<int> q;
	q.push(r);
	while (!q.empty()) {
		int h = q.front(), c = 0; q.pop();
		for (int nxt : g[h]) {
			if (visit[nxt]) continue;
			visit[nxt] = 1;
			++c;
			q.push(nxt);
		}
		if (!c) ++ans;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, x;i < n;++i) {
		cin >> x;
		if (x == -1) r = i;
		else g[x].emplace_back(i), g[i].emplace_back(x);
	}
	cin >> d;
	visit[d] = 1;
	bfs();
	cout << ans;
	return 0;
}