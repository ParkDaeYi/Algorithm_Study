#include <iostream>
#define INF 0x7fffffff/2
using namespace std;

// 플로이드 와샬
int n, m, graph[501][501], degree[501], ans;

void main_1() {

	cin >> n >> m;
	fill(graph[0], graph[n + 1], INF);
	for (int i = 0, x, y; i < m; ++i) cin >> x >> y, graph[x][y] = 1;
	// n의 최대 값이 500 이므로 플로이드 와샬 가능
	for (int via = 1; via <= n; ++via)
		for (int from = 1; from <= n; ++from) {
			for (int to = 1; to <= n; ++to) {
				if (graph[from][to] > graph[from][via] + graph[via][to])
					graph[from][to] = graph[from][via] + graph[via][to];
			}
		}
	// 예제의 입력 값으로 만든 다익스트라 그래프
	//		1	2	3	4	5	6
	//	1	X	2	X	2	1	3
	//	2	X	X	X	X	X	X
	//	3	X	2	X	1	X	2
	//	4	X	1	X	X	X	1
	//	5	X	1	X	1	X	2	
	//	6	X	X	X	X	X	X
	// 이 그래프를 어떻게 사용할 것이냐면
	// 각 정점의 행과 열에 있는 값 중 X가 아닌 1이상을 가지는 개수가
	// n - 1과 동일 할 경우 답이 됨
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (graph[i][j] != INF) {
				degree[i]++, degree[j]++;
				if (degree[i] == n - 1) ans++;
				if (degree[j] == n - 1) ans++;
			}
		}
	}
	cout << ans;

}

// BFS
#include <vector>
#include <queue>
int n, m, indegree[501], outdegree[501], ans;
bool visit[501];
vector<int> adj[501];

// indegree와 outdegree의 개수가 n + 1과 동일 할 경우 카운팅
// ==> while (!q.empty()) 에서 맨 처음 to와 from 값은 동일함
//		즉, 원래 계산 방식으로는 outdegree에만 + 1을 해줘야 하지만
//		indegree에도 + 1이 됬으므로 n + 1과 동일한 경우가 답이 됨
void solve(int from) {
	fill(visit + 1, visit + n + 1, 0);
	visit[from] = 1;
	queue<int> q;
	q.push(from);
	while (!q.empty()) {
		int to = q.front(); q.pop();
		indegree[to]++;
		outdegree[from]++;
		for (int nxt : adj[to]) {
			if (visit[nxt]) continue;
			visit[nxt] = 1;
			q.push(nxt);
		}
	}
	// indegree
	//		1	2	3	4	5	6
	//	1	1	1		1	1	1
	//	2		1
	//	3		1	1	1		1
	//	4		1		1		1
	//	5		1		1	1	1
	//	6						1
	// =>	1	5	1	4	2	5

	// outdegree
	//		1	2	3	4	5	6
	//	1	5
	//	2		1
	//	3			4
	//	4				3
	//	5					4
	//	6						1
	// =>	5	1	4	3	4	1
}

void main_2() {

	cin >> n >> m;
	for (int i = 0, x, y; i < m; ++i) cin >> x >> y, adj[x].push_back(y);
	for (int i = 1; i <= n; ++i) solve(i);
	for (int i = 1; i <= n; ++i) if (indegree[i] + outdegree[i] == n + 1) ans++;
	cout << ans;

}