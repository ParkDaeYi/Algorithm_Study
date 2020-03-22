//이건 많이 느리네요
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <functional>
//#define MAX_NODE 15625
//#define INF 1e9+1
//using namespace std;
//typedef pair<int,int> pii;
//
//int n, s, dist[MAX_NODE], ans, _map[MAX_NODE];
//vector<pii> graph[MAX_NODE];
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//
//	for (int t = 1;; t++) {
//		cin >> n;
//		if (!n) break;
//		for (int i = 0; i < n * n; ++i) cin >> _map[i];
//		for (int i = 0; i < n * n - 1; ++i) {
//			if (i % n != n - 1) {
//				graph[i].push_back({ _map[i + 1],i + 1 });
//				graph[i + 1].push_back({ _map[i],i });
//			}
//			if (i < n * (n - 1)) {
//				graph[i].push_back({ _map[i + n],i + n });
//				graph[i + n].push_back({ _map[i],i });
//			}
//		}
//		priority_queue<pii, vector<pii>, greater<pii>> pq;
//		pq.push({ 0,0 });
//		fill(dist, dist + n * n, INF); dist[0] = 0;
//		while (!pq.empty()) {
//			int cost = pq.top().first, cur = pq.top().second;
//			pq.pop();
//			if (cost > dist[cur]) continue;
//			for (pii next : graph[cur]) {
//				if (dist[next.second] > dist[cur] + next.first) {
//					dist[next.second] = dist[cur] + next.first;
//					pq.push(next);
//				}
//			}
//		}
//		cout << "Problem " << t << ": " << _map[0] + dist[n * n - 1] << '\n';
//		for (int i = 0; i < n * n; ++i) graph[i].clear();
//	}
//	return 0;
//}

#include <iostream>
#include <queue>
#include <functional>
#define MAX_NODE 125
#define INF 1e9+1
using namespace std;
typedef pair<int, pair<int, int>> pipii;
typedef pair<int, int> pii;

int n, graph[MAX_NODE][MAX_NODE], dist[MAX_NODE][MAX_NODE];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int dij();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int t = 1;; t++) {
		cin >> n;
		if (!n) break;
		for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> graph[i][j];
		cout << "Problem " << t << ": " << dij() << '\n';
	}
	return 0;
}

int dij() {
	fill(&dist[0][0], &dist[n - 1][n], INF); dist[0][0] = graph[0][0];
	priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
	pq.push(pipii(graph[0][0], pii(0, 0)));
	while (!pq.empty()) {
		int cost = pq.top().first, y = pq.top().second.first, x = pq.top().second.second;
		pq.pop();
		if (cost > dist[y][x]) continue;
		for (int i = 0; i < 4; ++i) {
			int ny = y + dir[i][0], nx = x + dir[i][1];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (dist[ny][nx] > cost + graph[ny][nx]) {
				dist[ny][nx] = cost + graph[ny][nx];
				pq.push(pipii(dist[ny][nx], pii(ny, nx)));
			}
		}
	}
	return dist[n - 1][n - 1];
}