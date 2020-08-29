#include <stdio.h>
#include <algorithm>
#include <vector>
#define N 100001
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;

struct Query {
	int op, idx, k, i, j;
	bool operator<(const Query& a) const {
		return k != a.k ? k < a.k : op < a.op;
	}
};
int n, q;
vector<Query> queries;
ll ans[N], seg[N * 4];

void upd(int node, int s, int e, int idx, int x) {
	if (idx < s || e < idx) return;
	if (s == e) seg[node] = x;
	else {
		int m = (s + e) >> 1;
		upd(node << 1, s, m, idx, x);
		upd(node << 1 | 1, m + 1, e, idx, x);
		seg[node] = seg[node << 1] + seg[node << 1 | 1];
	}
}

ll query(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	int m = (s + e) >> 1;
	return query(node << 1, s, m, l, r) + query(node << 1 | 1, m + 1, e, l, r);
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 0,x;i < n;++i) {
		scanf("%d", &x);
		upd(1, 1, n, i + 1, x);
	}
	scanf("%d\n", &q);
	int op, a, b, c, k = 0, idx = 0;
	while (q--) {
		Query tmp;
		scanf("%d", &op);
		tmp.op = op;
		if (op == 1) {
			tmp.k = ++k;
			scanf(" %d %d", &tmp.i, &tmp.j);
		}
		else {
			tmp.idx = idx++;
			scanf(" %d %d %d", &tmp.k, &tmp.i, &tmp.j);
		}
		queries.emplace_back(tmp);
	}
	sort(queries.begin(), queries.end());
	
	for (Query t : queries) {
		if (t.op == 1) upd(1, 1, n, t.i, t.j);
		else ans[t.idx] = query(1, 1, n, t.i, t.j);
	}
	for (int i = 0;i < idx;++i) printf("%lld\n", ans[i]);
	return 0;
}