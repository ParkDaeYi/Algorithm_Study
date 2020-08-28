// HLD(Heavy Light Decomposition)
//	- 트리의 간선들을 Heavy Edge(무거운 간선)와 Light Edge(가벼운 간선)로
//	 구분하는 것을 의미 (서브 트리의 크기를 기준으로 구분)
// https://justicehui.github.io/hard-algorithm/2020/01/24/hld/

#include <vector>
#include <cstdio>
#define N 100001
#pragma warning(disable:4996)
using namespace std;

int n, q, sz[N], dep[N], par[N], in[N], top[N], pv, seg[N * 4], lazy[N * 4];
/*
sz[i] = i 를 루트로 하는 서브트리의 크기
dep[i] = i 의 깊이
par[i] = i 의 부모 정점
top[i] = i 가 속한 체인의 가장 위에 있는 정점
in[i], out[i] = dfs ordering
g[i] = i 의 자식 정점
*/
bool used[N];
vector<int> adj[N], g[N];

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
		// 서브 트리가 가장 큰 자식을 맨 앞으로 보내주는 역할
		if (sz[i] > sz[g[v][0]]) swap(i, g[v][0]);
	}
}

void dfs3(int v = 1) {
	in[v] = ++pv;
	for (int& i : g[v]) {
		top[i] = i == g[v][0] ? top[v] : i;
		dfs3(i);
	}
	// out[v] = pv
}

void update_lazy(int node, int s, int e) {
	if (!lazy[node]) return;
	seg[node] += lazy[node] * (e - s + 1);
	if (s ^ e) {
		lazy[node << 1] += lazy[node];
		lazy[node << 1 | 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node, int s, int e, int l, int r, int v) {
	update_lazy(node, s, e);
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		lazy[node] += v;
		update_lazy(node, s, e);
		return;
	}
	int m = (s + e) >> 1;
	update_range(node << 1, s, m, l, r, v);
	update_range(node << 1 | 1, m + 1, e, l, r, v);
	seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

int query(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	int m = (s + e) >> 1;
	return query(node << 1, s, m, l, r) + query(node << 1 | 1, m + 1, e, l, r);
}

void update_hld(int a, int b, int v) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		int st = top[a];
		update_range(1, 1, n, in[st], in[a], v);
		a = par[st];
	}
	if (in[a] > in[b]) swap(a, b);
	// while 문과 위의 swap을 통해서 a는 lca가 됨
	// a 와 b는 같은 체인에 속하게 되므로
	// in[a] + 1, in[b] 를 통해 사이 경로의 범위를 지정할 수 있음
	// ==>	 dfs2 와 dfs3 을 통해 in[a] + 1 은
	//	(자신의 체인에 속한) 바로 밑 자식과 연결된 간선이다
	update_range(1, 1, n, in[a] + 1, in[b], v);
}

int query_hld(int a, int b) {
	int ret = 0;
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		int st = top[a];
		ret += query(1, 1, n, in[st], in[a]);
		a = par[st];
	}
	if (in[a] > in[b]) swap(a, b);
	return ret + query(1, 1, n, in[a] + 1, in[b]);
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);

	scanf("%d %d\n", &n, &q);
	for (int i = 1, a, b;i < n;++i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(); dfs2(); dfs3();
	while (q--) {
		char op; int a, b;
		scanf(" %c %d %d", &op, &a, &b);
		if (op == 'P') update_hld(a, b, 1);
		else printf("%d\n", query_hld(a, b));
	}
	return 0;
}
