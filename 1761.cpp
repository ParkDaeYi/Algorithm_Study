#include <iostream>
#include <vector>
#include <cmath>
#define MAX 40001
using namespace std;
typedef pair<int, int> pii;

const int max_level = (int)floor(log2(MAX));
int n, m, depth[MAX], dist[MAX], ac[MAX][20];
vector<pii> graph[MAX];

inline void swap_int(int& a, int& b) {
	int t = a; a = b; b = t; return;
}
void makeTree(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
		graph[to].push_back(make_pair(from, cost));
	}
	depth[0] = -1;
	makeTree(1, 0, 0);
	cin >> m;
	while (m--) {
		int a, b, ans_a, ans_b;
		cin >> a >> b;
		ans_a = a; ans_b = b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) swap_int(a, b);
			for (int i = max_level; i >= 0; --i) {
				if (depth[a] <= depth[ac[b][i]]) b = ac[b][i];
			}
		}
		int lca = a;
		if (a != b) {
			for (int i = max_level; i >= 0; --i) {
				if (ac[a][i] != ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}
		cout << dist[ans_a] + dist[ans_b] - 2 * dist[lca] << '\n';
	}
	return 0;
}

void makeTree(int here, int parent, int val) {
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;
	dist[here] += dist[parent] + val;
	for (int i = 1; i <= max_level; ++i) {
		int tmp = ac[here][i - 1];
		ac[here][i] = ac[tmp][i - 1];
	}
	for (pii next : graph[here]) {
		if (next.first != parent) makeTree(next.first, here, next.second);
	}
	return;
}