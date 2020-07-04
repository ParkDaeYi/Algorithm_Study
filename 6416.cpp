#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

int minNode = 1e9, maxNode, edge;
int ind[MAX], outd[MAX];
bool chk[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int t = 1, u, v;;) {
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		else if (!u && !v) {
			bool flag = 0;
			int root = 0, node = 0;
			for (int i = minNode; i <= maxNode; ++i) {
				if (!chk[i]) continue;
				node++;	// 정점의 수 카운팅
				if (!ind[i] && outd[i]) root++;	// 들어오는 선은 없고 나가는 선만 있는 경우 root
				if (ind[i] >= 2) flag = 1;	// 예외 처리
			}
			if (node != edge + 1 || root > 1) flag = 1;	// 예외 처리
			if (!flag || !edge) cout << "Case " << t << " is a tree.\n";
			else cout << "Case " << t << " is not a tree.\n";

			fill(ind, ind + MAX, 0);
			fill(outd, outd + MAX, 0);
			fill(chk, chk + MAX, 0);
			minNode = 1e9; edge = maxNode = 0; t++; 
			continue;
		}
		else {
			chk[u] = chk[v] = 1;	// 사용한 정점 체크
			minNode = min(minNode, min(u, v));	// 가장 작은 숫자를 가진 정점
			maxNode = max(maxNode, max(u, v));	// 가장 큰 숫자를 가진 정점
			ind[v]++;	// 들어오는 간선의 수 (indegree)
			outd[u]++;	// 나가는 간선의 수	(outdegree)
			edge++;	// 간선의 수
		}
	}
	return 0;
}