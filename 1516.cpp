#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> pii;

int n, cost[501], indegree[501];
vector<int> graph[501];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, c, x; i <= n; ++i) {
		cin >> c;
		cost[i] = c;
		while (1) {
			cin >> x;
			if (x == -1) break;
			indegree[i]++;	// 들어오는 간선 추가
			graph[x].push_back(i);	// 간선 연결 x -> i
		}
	}

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	// cost가 가장 작은 순으로 저장
	// ==> 두 개 이상의 건물이 완성되어야 지을 수 있는 건물의 경우를
	//		처리하기 위함
	for (int i = 1; i <= n; ++i) if (!indegree[i]) pq.push({ cost[i],i });
	while (!pq.empty()) {
		int cur = pq.top().second; pq.pop();
		for (int nxt : graph[cur]) {
			if (!--indegree[nxt]) {
				// indegree[nxt]가 0이면 해당 건물을 지을 수 있음
				// 이때 힙의 경우 시간이 가장 적게 걸리는 순서로 저장하였으므로
				// cost[cur]의 경우 가장 오래 걸리는 건물의 시간이 됨
				cost[nxt] += cost[cur];
				pq.push({ cost[nxt],nxt });
			}
		}
	}
	for (int i = 1; i <= n; ++i) cout << cost[i] << '\n';
	return 0;
}