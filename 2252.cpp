#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, indegree[32001];
vector<int> graph[32001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0, x, y; i < M; ++i) {
		cin >> x >> y;
		graph[x].push_back(y);	// 단방향 그래프
		indegree[y]++;	// 들어오는 간선 추가
	}
	queue<int> q;
	// indegree[i] 가 0일 경우 ==> 앞에 서면 됨
	for (int i = 1; i <= N; ++i) if (!indegree[i]) q.push(i);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << ' ';
		for (int nxt : graph[cur]) {
			if (!--indegree[nxt]) q.push(nxt);
		}
	}
	return 0;
}