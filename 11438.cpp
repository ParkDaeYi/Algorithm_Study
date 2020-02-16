#include <iostream>
#include <vector>
#include <cmath>
#define MAX_NODE 100001
using namespace std;

const int max_level = (int)floor(log2(MAX_NODE));
int n, m, depth[MAX_NODE], ac[MAX_NODE][20];
vector<int> graph[MAX_NODE];

inline void swap(int& a, int& b) {
	int t = a; a = b; b = t; return;
}

void getTree(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	depth[0] = -1;
	getTree(1, 0);

	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		if (depth[a] != depth[b]) {
			if (depth[a] > depth[b]) swap(a, b);
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
		cout << lca << '\n';
	}
	return 0;
}

void getTree(int here, int parent) {
	depth[here] = depth[parent] + 1;
	ac[here][0] = parent;
	for (int i = 1; i <= max_level; ++i) {
		int tmp = ac[here][i - 1];
		ac[here][i] = ac[tmp][i - 1];
	}
	for (int there : graph[here]) {
		if (there != parent) getTree(there, here);
	}
	return;
}