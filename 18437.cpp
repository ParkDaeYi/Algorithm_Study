#include <cstdio>
#include <vector>
#define N 100001
#pragma warning(disable:4996)
using namespace std;

int n, m, l[N], r[N], seg[N * 4], lazy[N * 4], sz;
vector<int> adj[N];

void range(int idx) {
	l[idx] = ++sz;
	for (int& nxt : adj[idx]) range(nxt);
	r[idx] = sz;
}

void update_lazy(int node, int s, int e) {
	// 0으로 갱신하기 때문에 lazy[node]가 비었을 시 -1로 처리
	if (lazy[node] == -1) return;
	seg[node] = lazy[node] * (e - s + 1);
	if (s ^ e) {
		lazy[node << 1] = lazy[node];
		lazy[node << 1 | 1] = lazy[node];
	}
	lazy[node] = -1;
}

void update_range(int node, int s, int e, int l, int r, int v) {
	update_lazy(node, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		lazy[node] = v;
		update_lazy(node, s, e);
		return;
	}
	int mid = (s + e) >> 1;
	update_range(node << 1, s, mid, l, r, v);
	update_range(node << 1 | 1, mid + 1, e, l, r, v);
	seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

int query(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	int mid = (s + e) >> 1;
	return query(node << 1, s, mid, l, r) + query(node << 1 | 1, mid + 1, e, l, r);
}

int main() {
	scanf("%d\n", &n);
	for (int i = 1, a;i <= n;++i) {
		scanf("%d", &a);
		if (!a) continue;
		adj[a].push_back(i);
	}
	range(1);
	update_range(1, 1, n, 1, n, 1);
	scanf("%d\n", &m);
	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		// l[b] + 1 ==> 자기 자신 제외
		if (a == 1) update_range(1, 1, n, l[b] + 1, r[b], 1);
		// 컴퓨터를 끄는 경우 0으로 갱신
		else if (a == 2) update_range(1, 1, n, l[b] + 1, r[b], 0);
		else printf("%d\n", query(1, 1, n, l[b] + 1, r[b]));
	}
	return 0;
}