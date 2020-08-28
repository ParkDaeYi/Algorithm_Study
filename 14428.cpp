#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 100001
#pragma warning(disable:4996)
using namespace std;
typedef pair<int, int> pii;

int n, m;
pii arr[N], seg[N * 4];

void init(int node,int s,int e) {
	if (s == e) seg[node] = arr[s];
	else {
		int m = (s + e) >> 1;
		init(node << 1, s, m);
		init(node << 1 | 1, m + 1, e);
		seg[node] = min(seg[node << 1], seg[node << 1 | 1]);
	}
}

void upd(int node, int s, int e, int p, int v) {
	if (p < s || e < p) return;
	if (s == e) {
		seg[node].first = v;
		return;
	}
	int m = (s + e) >> 1;
	upd(node << 1, s, m, p, v);
	upd(node << 1 | 1, m + 1, e, p, v);
	seg[node] = min(seg[node << 1], seg[node << 1 | 1]);
}

pii query(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return pii(1e9 + 1, 1e9 + 1);
	if (l <= s && e <= r) return seg[node];
	int m = (s + e) >> 1;
	return min(query(node << 1, s, m, l, r), query(node << 1 | 1, m + 1, e, l, r));
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 1;i <= n;++i) {
		scanf("%d", &arr[i].first);
		arr[i].second = i;
	}
	init(1, 1, n);
	scanf("%d\n", &m);
	while (m--) {
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		if (op == 1) upd(1, 1, n, a, b);
		else printf("%d\n", query(1, 1, n, a, b).second);
	}
	return 0;
}