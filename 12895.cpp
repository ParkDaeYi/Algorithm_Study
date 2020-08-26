#include <iostream>
#include <cstdio>
#define N 100001
#pragma warning(disable:4996)
using namespace std;

int n, t, q, seg[N * 4], lazy[N * 4];

void update_lazy(int node, int s, int e) {
	if (!lazy[node]) return;
	seg[node] = lazy[node];
	if (s ^ e) {
		lazy[node << 1] = lazy[node];
		lazy[node << 1 | 1] = lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node, int s, int e, int l, int r, int v) {
	update_lazy(node, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		lazy[node] = v;
		update_lazy(node, s, e);
		return;
	}
	int m = (s + e) >> 1;
	update_range(node << 1, s, m, l, r, v);
	update_range(node << 1 | 1, m + 1, e, l, r, v);
	seg[node] = seg[node << 1] | seg[node << 1 | 1];
}

int query(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	int m = (s + e) >> 1;
	return query(node << 1, s, m, l, r) | query(node << 1 | 1, m + 1, e, l, r);
}

int main() {
	scanf("%d %d %d\n", &n, &t, &q);
	update_range(1, 1, n, 1, n, 1);
	while (q--) {
		char op; int a, b, c;
		scanf(" %c %d %d", &op, &a, &b);
		if (a > b) swap(a, b);
		if (op == 'C') {
			scanf(" %d", &c);
			update_range(1, 1, n, a, b, 1 << (c - 1));
		}
		else {
			int t = query(1, 1, n, a, b), cnt = 0;
			while (t) {
				cnt += (t & 1);
				t >>= 1;
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}