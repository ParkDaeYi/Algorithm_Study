#include <iostream>
#include <vector>
#include <queue>
#define N 501
#define INF 0x7fffffff
using namespace std;
typedef pair<int, int> pii;

int n, m, src, dest, dist[N];
vector<pii> graph[N];
vector<int> trace[N];

// 처음 dijkstra에서 최단 경로와
// trace를 통해 최단 경로인 정점을 수집(역순으로 활용할 수 있게끔)
// 그 후 dijkstra에서 최단 경로를 제외한
// 그 다음 최단 경로를 구함
int dijkstra() {
	fill(dist, dist + n, INF);
	dist[src] = 0;
	priority_queue<pii, vector<pii>, less<pii>> pq;
	pq.push({ 0,src });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (dist[cur] < cost) continue;
		for (pii& p : graph[cur]) {
			// 최단 경로를 제외한 정점일 경우 continue
			// ==> 최단 경로에 포함되지 않는 경로이기 때문에
			//		최단 경로에 포함되는 경로는 제외 시킴
			if (p.first == -1) continue;
			int nxt = p.second;
			int ncost = p.first + cost;
			if (dist[nxt] > ncost) {
				dist[nxt] = ncost;
				pq.push({ -ncost,nxt });

				// 최단 경로를 구하는 것이 목표이므로
				// 더 나은 경로가 발견 되었을 시 clear를 해줌
				trace[nxt].clear();
				// 역순으로 탐색할 수 있게 저장
				trace[nxt].push_back(cur);
			}
			else if (dist[nxt] == ncost) trace[nxt].push_back(cur);
		}
	}
	return dist[dest];
}

// bfs를 통해 최단 경로를 제외 시키기 위한 과정
void bfs() {
	queue<int> q;
	q.push(dest);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int& i : trace[cur]) {
			for (pii& p : graph[i]) if (p.second == cur) p.first = -1;
			q.push(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (cin >> n >> m) {
 		if (!n && !m) break;
		cin >> src >> dest;
		for (int i = 0, a, b, c;i < m;++i) {
			cin >> a >> b >> c;
			graph[a].push_back({ c,b });
		}
		dijkstra();
		bfs();
		int ans = dijkstra();
		cout << (ans == INF ? -1 : ans) << '\n';
		for (int i = 0;i < n;++i) graph[i].clear(), trace[i].clear();
	}
	return 0;
}