#include <iostream>
#include <vector>
#define MAX_N 100001
using namespace std;
typedef long long int llt;

int n, m, l[MAX_N], r[MAX_N];
llt seg[MAX_N * 4], lazy[MAX_N * 4];
vector<int> p[MAX_N];

void dfs(int idx, int& c) {
	l[idx] = ++c;
	for (int nxt : p[idx]) dfs(nxt, c);
	r[idx] = c;
}

void update_lazy(int node, int s, int e) {
	if (!lazy[node]) return;
	seg[node] += lazy[node];
	if (s != e) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node, int s, int e, int left, int right, int val) {
	update_lazy(node, s, e);
	if (e < left || right < s) return;
	if (left <= s && e <= right) {
		seg[node] += val;
		if (s != e) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (s + e) >> 1;
	update_range(node * 2, s, mid, left, right, val);
	update_range(node * 2 + 1, mid + 1, e, left, right, val);
}

llt query(int node, int s, int e, int idx) {
	update_lazy(node, s, e);
	if (e < idx || idx < s) return 0;
	if (s == e) return seg[node];
	int mid = (s + e) >> 1;
	return query(node * 2, s, mid, idx) + query(node * 2 + 1, mid + 1, e, idx);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1, x;i < n + 1;++i) {
		cin >> x;
		if (x == -1) continue;
		p[x].push_back(i);
	}
	int c = 0;
	dfs(1, c);
	while (m--) {
		int op, x, y;
		cin >> op >> x;
		if (op == 1) {
			cin >> y;
			update_range(1, 1, n, l[x], r[x], y);
		}
		else cout << query(1, 1, n, l[x]) << '\n';		
	}
	return 0;
}