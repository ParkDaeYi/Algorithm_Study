#include <iostream>
#include <cmath>
#include <vector>
#define MAX_N 100001
using namespace std;

const int max_level = (int)floor(log2(MAX_N));
int n, m, depth[MAX_N], ac[MAX_N][20];
vector<int> graph[MAX_N];

void makeTree(int now, int parent) {
	// 예제 입력을 토대로 하면 depth 배열은
	//	i	1	2	3	4	5	6	7	8	9	10	11	12	13	14	15
	//	d	0	1	1	2	2	2	2	2	3	3	3	3	3	3	4

	//	ac 배열은
	//		0	1	2	==> 2^n 위에 있는 조상의 번호로 이루어져 있음
	//	1	0
	//	2	1	0
	//	3	1	0
	//	4	2	1	0
	//	5	2	1	0
	//	6	2	1	0
	//	7	3	1	0
	//	8	3	1	0
	//	9	4	2	0
	//	10	4	2	0
	//	11	5	2	0
	//	12	5	2	0
	//	13	7	3	0
	//	14	7	3	0
	//	15	11	5	1	0
	depth[now] = depth[parent] + 1;
	ac[now][0] = parent;
	for (int i = 1, tmp;i <= max_level;++i) {
		tmp = ac[now][i - 1];
		ac[now][i] = ac[tmp][i - 1];
	}
	for (int nxt : graph[now]) {
		if (nxt != parent) makeTree(nxt, now);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, x, y;i < n;++i) {
		cin >> x >> y;
		// 트리의 노드들을 양방향으로 엮어준다
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	// 트리의 루트의 depth를 0으로 할 것임
	// 정점들은 1부터 시작하므로 depth 배열의 0번째 인덱스에 -1을 넣음
	depth[0] = -1;
	makeTree(1, 0);

	cin >> m;
	int a, b, lca;
	while (m--) {
		cin >> a >> b;
		// 우선 depth 먼저 비교
		if (depth[a] != depth[b]) {
			// 연산의 편의를 위해 b가 a보다 깊은 것으로 설정
			if (depth[a] > depth[b]) swap(a, b);
			for (int i = max_level;i >= 0;--i) {
				// b의 조상 값을 통해 비교
				if (depth[a] <= depth[ac[b][i]]) b = ac[b][i];
			}
		}
		lca = a;
		// 깊이는 같은데 서로 값이 다를 경우
		if (a != b) {
			for (int i = max_level;i >= 0;--i) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}
		cout << lca << '\n';
	}
	return 0;
}