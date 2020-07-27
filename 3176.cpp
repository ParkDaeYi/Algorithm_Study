#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define MAX_N 100000
using namespace std;
typedef pair<int, int> pii;

// 해당 문제에서 
// "모든 도시의 쌍에는 그 도시를 연결하는 유일한 경로가 있고" 라는 문구를 통해
// LCA로 접근할 수 있음
const int max_level = (int)floor(log2(MAX_N));
int n, k, depth[MAX_N], ac[MAX_N][20], min_dist[MAX_N][20], max_dist[MAX_N][20];
vector<pii> graph[MAX_N];

void makeTree(int now, int parent, int dist) {
	depth[now] = depth[parent] + 1;
	ac[now][0] = parent;
	// 거리 값도 기존의 ac 배열과 비슷하게 갱신함
	// 거리 값은 자신의 각각 조상까지의 최소/최대 거리를 가지고 있음
	min_dist[now][0] = max_dist[now][0] = dist;
	for (int i = 1, tmp;i <= max_level;++i) {
		tmp = ac[now][i - 1];
		ac[now][i] = ac[tmp][i - 1];
		min_dist[now][i] = min(min_dist[now][i - 1], min_dist[tmp][i - 1]);
		max_dist[now][i] = max(max_dist[now][i - 1], max_dist[tmp][i - 1]);
	}
	for (pii nxt : graph[now]) {
		if (nxt.first != parent) makeTree(nxt.first, now, nxt.second);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, x, y, z;i < n;++i) {
		cin >> x >> y >> z;
		graph[x].push_back({ y,z });
		graph[y].push_back({ x,z });
	}
	depth[0] = -1;
	makeTree(1, 0, 0);

	cin >> k;
	while (k--) {
		int a, b, ans_min = 1e6, ans_max = 0;
		cin >> a >> b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) swap(a, b);
			for (int i = max_level;i >= 0;--i) {
				if (depth[a] <= depth[ac[b][i]]) {
					ans_min = min(ans_min, min_dist[b][i]);
					ans_max = max(ans_max, max_dist[b][i]);
					b = ac[b][i];
				}
			}
		}

		if (a != b) {
			for (int i = max_level;i >= 0;--i) {
				if (ac[a][i] != ac[b][i]) {
					ans_min = min(ans_min, min(min_dist[a][i], min_dist[b][i]));
					ans_max = max(ans_max, max(max_dist[a][i], max_dist[b][i]));
					a = ac[a][i];
					b = ac[b][i];
				}
			}
			// a와 b는 공통 조상 바로 아래에 있기 때문에
			// 자신의 조상까지의 최소/최대 거리를 한 번 더 갱신해야 함
			ans_min = min(ans_min, min(min_dist[a][0], min_dist[b][0]));
			ans_max = max(ans_max, max(max_dist[a][0], max_dist[b][0]));
		}
		cout << ans_min << ' ' << ans_max << '\n';
	}
	return 0;
}