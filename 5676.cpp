#include <stdio.h>
#include <math.h>
#define N 100001
#pragma warning(disable:4996)

int n, m, seg[1 << 18];

inline int trans(int x) {
	return x == 0 ? 0 : x > 0 ? 1 : -1;
}

int query(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return 1;
	if (l <= s && e <= r) return seg[node];
	int mid = (s + e) >> 1;
	return query(node << 1, s, mid, l, r) * query(node << 1 | 1, mid + 1, e, l, r);
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	while (scanf("%d %d\n", &n, &m) == 2) {
		const int sz = pow(2, (int)log2(n - 1) + 1);
		for (int i = 0, x;i < n;++i) {
			scanf("%d", &x);
			seg[sz + i] = trans(x);
		}
		for (int i = n;i < sz;++i) seg[sz + i] = 1;
		for (int i = sz - 1;i > 0;--i) seg[i] = seg[i << 1] * seg[i << 1 | 1];
		char op; int a, b;
		while (m--) {
			scanf(" %c %d %d", &op, &a, &b);
			if (op == 'C') {
				int node = a + sz - 1;
				seg[node] = trans(b);
				for (node /= 2;node > 0;node /= 2) seg[node] = seg[node << 1] * seg[node << 1 | 1];
			}
			else {
				int ans = query(1, 1, sz, a, b);
				if (!ans) printf("0");
				else printf("%c", ans > 0 ? '+' : '-');
			}
		}
		printf("\n");
	}
	return 0;
}