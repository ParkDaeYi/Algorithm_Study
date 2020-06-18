#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX_N 500
#define VERTEX 500+2
#define S VERTEX-2
#define E VERTEX-1
#define INF 1e9
using namespace std;

int n, c[VERTEX][VERTEX], f[VERTEX][VERTEX], ans;
int level[VERTEX];	// 레벨 그래프에서 각 정점의 레벨을 저장 (S는 0)
int work[VERTEX];	// DFS 중 해당 정점이 몇 번째 간선까지 탐색했는지 기억하는 용도
vector<int> adj[VERTEX];

// 디닉 전용 BFS 함수
bool bfs() {
	// 레벨 값 초기화
	fill(level, level + VERTEX, -1);
	level[S] = 0;

	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			// 레벨 값이 설정되지 않았고, 간선에 잔여량이 남아있을 경우 이동
			if (level[nxt] == -1 && c[cur][nxt] > f[cur][nxt]) {
				level[nxt] = level[cur] + 1; // next의 레벨은 current + 1
				q.push(nxt);
			}
		}
	}
	// 싱크에 도달하면 true
	return level[E] != -1;
}

// 디닉 전용 DFS 함수, curr에서 dest까지 최대 flow만큼의 유량을 보냄
int dfs(int cur, int dest, int flow) {
	if (cur == dest) return flow;

	// 현재 정점에서 인접한 정점들을 탐색
	// 이때, 이번 단계에서 이미 쓸모없다고 판단한 간선은 다시 볼 필요가 없기 때문에
	// work 배열로 탐색한 간선의 수를 카운팅함
	for (int& i = work[cur];i < adj[cur].size();++i) {
		int nxt = adj[cur][i];
		// nxt의 레벨이 cur의 레벨 + 1 이고, 간선에 잔여량이 남아있으면 이동
		if (level[nxt] == level[cur] + 1 && c[cur][nxt] > f[cur][nxt]) {
			// ret: flow와 다음 dfs함수의 결과 중 최솟값
			// 결과적으로 경로상의 간선들 중 가장 작은 유량이 됨
			int ret = dfs(nxt, dest, min(c[cur][nxt] - f[cur][nxt], flow));
			// 싱크까지의 경로가 있다면 유량을 ret만큼 흘리고 종료
			if (ret > 0) {
				f[cur][nxt] += ret;
				f[nxt][cur] -= ret;
				return ret;
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, x;i < n;++i) {
		cin >> x;
		if (x == 1) {
			c[S][i] = INF;
			adj[S].push_back(i);
			adj[i].push_back(S);
		}
		else if (x == 2) {
			c[i][E] = INF;
			adj[E].push_back(i);
			adj[i].push_back(E);
		}
	}
	for (int i = 0;i < n;++i)
		for (int j = 0;j < n;++j) {
			cin >> c[i][j];
			if (i != j) adj[i].push_back(j);
		}

	// 디닉 알고리즘 수행
	// 레벨 그래프를 구축하여 싱크에 도달 가능한 동안 반복
	while (bfs()) {
		fill(work, work + VERTEX, 0);
		// 차단 유량(blocking flow) 구하기
		while (1) {
			int flow = dfs(S, E, INF); // DFS를 사용하여 각 경로를 찾음
			if (!flow) break; // 경로가 없을 경우 종료
			ans += flow;
		}
	}
	cout << ans << '\n'; // 슬픔의 정도의 최소 합 출력

	// 각 진영에 속한 사람을 판단하기 위해 소스에서의 도달 가능성 판별
	bool visited[VERTEX] = { 0, };
	visited[S] = 1;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			// 여유 용량이 남아있는 간선만 이용
			if (!visited[nxt] && c[cur][nxt] > f[cur][nxt]) {
				visited[nxt] = 1;
				q.push(nxt);
			}
		}
	}
	// A 진영: 소스에서 도달 가능
	for (int i = 0;i < n;++i) if (visited[i]) cout << i + 1 << ' ';
	cout << '\n';
	// B 진영: 소스에서 도달 불가능
	for (int i = 0;i < n;++i) if (!visited[i]) cout << i + 1 << ' ';
	cout << '\n';
	return 0;
}