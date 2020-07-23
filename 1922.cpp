#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

// 프림
int n, m, cnt, ans;
bool visit[1001];
vector<pii> graph[1001];

void Prim() {

	cin >> n >> m;
	for (int i = 0, a, b, c; i < m; ++i) {
		cin >> a >> b >> c;
		// 우선 순위 큐에서 비용을 기준으로 정렬할 것이므로
		// c 를 first에 저장
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	// 출발 지점을 1로 선택 (아무거나 상관 없음)
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int cur = pq.top().second, cost = pq.top().first;
		pq.pop();
		if (visit[cur]) continue;
		visit[cur] = 1;
		ans += cost;
		// 모든 정점을 방문 했을 경우
		if (++cnt == n) break;
		for (pii nxt : graph[cur]) {
			if (visit[nxt.second]) continue;
			pq.push(nxt);
		}
	}
	cout << ans;

}

// 크루스칼
struct Node {
	int f, t, c;
}adj[100001];
int n, m, parent[1001], ans;

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void Kruskal() {

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) parent[i] = i;	// 자기 자신을 저장 (초기 값)
	for (int i = 0, a, b, c; i < m; ++i) cin >> adj[i].f >> adj[i].t >> adj[i].c;
	// 비용을 기준으로 오름차순 정렬
	sort(adj, adj + m, [](const Node& n1, const Node& n2) {
		return n1.c < n2.c;
	});
	for (int i = 0; i < m; ++i) {
		int from = adj[i].f, to = adj[i].t, cost = adj[i].c;
		from = getParent(from);
		to = getParent(to);
		// from 과 to의 부모가 같다는 말은
		// from 과 to가 연결되어 있다는 뜻
		if (from == to) continue;
		ans += cost;
		if (from < to) swap(from, to);
		parent[to] = from;
	}
	cout << ans;

}