#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define N 100
#define M 2*(N+1)
#define S M-2
#define E M-1
#define INF 0x7fffffff
#pragma warning(disable:4996)
using namespace std;

// 네트워크 플로우와는 다르게 거리 값을 저장하는 d를 추가
int n, m, c[M][M], f[M][M], d[M][M], ans;
vector<int> g[M];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	// 사람 - E
	for (int i = N; i < N + n; ++i) {
		cin >> c[i][E];
		g[i].emplace_back(E);
		g[E].emplace_back(i);
	}
	// S - 서점
	for (int i = 0; i < m; ++i) {
		cin >> c[S][i];
		g[S].emplace_back(i);
		g[i].emplace_back(S);
	}
	// 사람과 서점 사이 간선 추가
	for (int i = 0; i < m; ++i) {
		for (int j = N; j < N + n; ++j) {
			cin >> d[i][j];
			d[j][i] = -d[i][j];
			c[i][j] = INF;
			g[i].emplace_back(j);
			g[j].emplace_back(i);
		}
	}
	// MCMF
	while (1) {
		int prev[M], dist[M];
		bool visit[M] = { 0, };	// 큐 안에 정점 확인용도
		fill(prev, prev + M, -1);
		fill(dist, dist + M, INF);
		queue<int> q;
		q.push(S);
		dist[S] = 0;
		visit[S] = 1;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			visit[cur] = 0;
			for (int nxt : g[cur]) {
				// 최단 거리를 구해야하기 때문에 dist도 같이 확인
				if (c[cur][nxt] > f[cur][nxt] && dist[nxt] > dist[cur] + d[cur][nxt]) {
					dist[nxt] = dist[cur] + d[cur][nxt];
					prev[nxt] = cur;
					if (!visit[nxt]) {
						q.push(nxt);
						visit[nxt] = 1;
					}
				}
			}
		}
		if (prev[E] == -1) break;
		int flow = INF;
		for (int i = E; i != S; i = prev[i]) flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
		for (int i = E; i != S; i = prev[i]) {
			ans += flow * d[prev[i]][i];	// 결과 = 경로의 비용 합 * 유량
			f[prev[i]][i] += flow;
			f[i][prev[i]] -= flow;
		}
	}
	cout << ans;
	return 0;
}