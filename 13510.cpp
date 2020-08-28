#include <stdio.h>
#include <vector>
#define N 100001
#pragma warning(disable:4996)

int n, q, u[N], v[N], w[N], sz[N], dep[N], par[N], in[N], top[N], pv, seg[N * 4];
bool used[N];
std::vector<int> adj[N], g[N];

void swap(int& a, int& b) { int t = a;a = b;b = t; }

void dfs1(int v = 1) {
	used[v] = 1;
	for (int& i : adj[v]) {
		if (used[i]) continue;
		used[i] = 1;
		g[v].push_back(i);
		dfs1(i);
	}
}

void dfs2(int v = 1) {
	sz[v] = 1;
	for (int& i : g[v]) {
		dep[i] = dep[v] + 1;
		par[i] = v;
		dfs2(i);
		sz[v] += sz[i];
		if (sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
	}
}

void dfs3(int v = 1) {
	in[v] = ++pv;
	for (int& i : g[v]) {
		top[i] = i == g[v][0] ? top[v] : i;
		dfs3(i);
	}
}

void update_seg(int node, int s, int e, int p, int v) {
	if (p < s || e < p) return;
	if (s == e) {
		seg[node] = v;
		return;
	}
	int m = (s + e) >> 1;
	update_seg(node << 1, s, m, p, v);
	update_seg(node << 1 | 1, m + 1, e, p, v);
	seg[node] = seg[node << 1] > seg[node << 1 | 1] ? seg[node << 1] : seg[node << 1 | 1];
}

int query_seg(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	int m = (s + e) >> 1;
	int a = query_seg(node << 1, s, m, l, r);
	int b = query_seg(node << 1 | 1, m + 1, e, l, r);
	return a > b ? a : b;
}

int query_hld(int a, int b) {
	int ret = 0, qry;
	while (top[a] ^ top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		int st = top[a];
		qry = query_seg(1, 1, n, in[st], in[a]);
		ret = ret > qry ? ret : qry;
		a = par[st];
	}
	if (in[a] > in[b]) swap(a, b);
	qry = query_seg(1, 1, n, in[a] + 1, in[b]);
	return ret > qry ? ret : qry;
}

int main() {
	scanf("%d\n", &n);
	for (int i = 1;i < n;++i) {
		scanf("%d %d %d", u + i, v + i, w + i);
		adj[u[i]].push_back(v[i]);
		adj[v[i]].push_back(u[i]);
	}
	dfs1(); dfs2(); dfs3();
	// 루트인 1 이 update 되지 않도록 하기 위해
	// 사전에 u 와 v 의 값을 조정함
	// ==>	 in(degree) 을 통해 update 및 query 를 연산하는데
	//		1 의 경우 in 이 없기 때문
	for (int i = 1;i < n;++i) {
		if (par[v[i]] == u[i]) swap(u[i], v[i]);
		update_seg(1, 1, n, in[u[i]], w[i]);
	}
	scanf("%d\n", &q);
	while (q--) {
		int op, a, b;
		scanf("%d %d %d", &op, &a, &b);
		if (op == 1) update_seg(1, 1, n, in[u[a]], b);
		else printf("%d\n", query_hld(a, b));
	}
	return 0;
}