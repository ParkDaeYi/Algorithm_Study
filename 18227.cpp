#include <stdio.h>
#include <vector>
#define N 200001
#pragma warning(disable:4996)
typedef long long ll;

int n, c, q, dep[N], in[N], out[N], pv;
ll seg[N * 4];
std::vector<int> g[N];

void dfs(int v, int d) {
	dep[v] = d;
	in[v] = ++pv;
	for (int& i : g[v]) {
		if (dep[i]) continue;
		dfs(i, d + 1);
	}
	out[v] = pv;
}

void upd(int node, int s, int e, int idx) {
	if (idx < s || e < idx) return;
	seg[node]++;
	if (s ^ e) {
		int m = (s + e) >> 1;
		upd(node << 1, s, m, idx);
		upd(node << 1 | 1, m + 1, e, idx);
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
	scanf("%d %d\n", &n, &c);
	for (int i = 1, a, b;i < n;++i) {
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	// dfs로 각 정점의 indegree와 outdegree를 구함
	// outdegree가 하나 이상일 경우
	// 가장 큰 수로 지정
	// ==>	 한 정점의 in 에서 out 까지의 범위는
	//		모두 그 정점에 영향을 미침(갱신된 횟수)
	dfs(c, 1);
	scanf("%d\n", &q);
	int op, x;
	while (q--) {
		scanf("%d %d", &op, &x);
		if (op == 1) upd(1, 1, n, in[x]);
		else printf("%lld\n", query(1, 1, n, in[x], out[x]) * dep[x]);
	}
	return 0;
}


// 굳이 HLD로 짜봄(솔루션은 위와 같음)

int n, c, q, sz[N], dep[N], par[N], in[N], out[N], top[N], pv;
std::vector<int> adj[N], g[N];
bool used[N];
ll seg[N * 4], lazy[N * 4];

void dfs1(int v) {
	used[v] = 1;
	for (int& i : adj[v]) {
		if (used[i]) continue;
		used[i] = 1;
		g[v].push_back(i);
		dfs1(i);
	}
}

void dfs2(int v) {
	sz[v] = 1;
	for (int& i : g[v]) {
		dep[i] = dep[v] + 1;
		par[i] = v;
		dfs2(i);
		sz[v] += sz[i];
		if (sz[i] > sz[g[v][0]]) std::swap(i, g[v][0]);
	}
}

void dfs3(int v) {
	in[v] = ++pv;
	for (int& i : g[v]) {
		top[i] = i == g[v][0] ? top[v] : i;
		dfs3(i);
	}
	out[v] = pv;
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

void update_range(int node, int s, int e, int l, int r, ll v) {
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

ll query_seg(int node, int s, int e, int idx) {
	update_lazy(node, s, e);
	if (idx < s || e < idx) return 0;
	if (s == e) return seg[node];
	int m = (s + e) >> 1;
	return query_seg(node << 1, s, m, idx) + query_seg(node << 1 | 1, m + 1, e, idx);
}

void update_hld(int a, int b, ll v) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) std::swap(a, b);
		int st = top[a];
		update_range(1, 1, n, in[st], in[a], v);
		a = par[st];
	}
	if (in[a] > in[b]) std::swap(a, b);
	update_range(1, 1, n, in[a], in[b], v);
}

int solve_2() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d %d\n", &n, &c);
	for (int i = 1, a, b;i < n;++i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(c); dfs2(c); dfs3(c);
	scanf("%d\n", &q);
	int op, a;
	while (q--) {
		scanf("%d %d", &op, &a);
		if (op == 1) update_hld(c, a, 1);
		else printf("%lld\n", query_seg(1, 1, n, in[a]) * (dep[a] + 1));
	}
	return 0;
}