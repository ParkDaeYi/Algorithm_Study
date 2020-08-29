// 최소 세그먼트 트리 풀이
#include <stdio.h>
#include <vector>
#include <algorithm>
#define N 100001
#pragma warning(disable:4996)

int n, q, sz[N], dep[N], par[N], in[N], top[N], pv, seg[N * 4], vtx[N];
std::vector<int> adj[N], g[N];
bool used[N], st[N];

inline int min(int a, int b) { return a < b ? a : b; }

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
		if (sz[i] > sz[g[v][0]]) std::swap(i, g[v][0]);
	}
}

void dfs3(int v = 1) {
	in[v] = ++pv; vtx[pv] = v;	// vtx에 정점 번호 저장
	for (int& i : g[v]) {
		top[i] = i == g[v][0] ? top[v] : i;
		dfs3(i);
	}
}

void su(int node, int s, int e, int idx) {
	if (idx < s || e < idx) return;
	if (s == e) {
		st[idx] ^= 1;
		seg[node] = st[idx] ? idx : N;	// 검은돌일 경우 idx, 흰돌 N(==INF)
		return;
	}
	int m = (s + e) >> 1;
	su(node << 1, s, m, idx);
	su(node << 1 | 1, m + 1, e, idx);
	seg[node] = min(seg[node << 1], seg[node << 1 | 1]);
}

int sq(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return N;
	if (l <= s && e <= r) return seg[node];
	int m = (s + e) >> 1;
	return min(sq(node << 1, s, m, l, r), sq(node << 1 | 1, m + 1, e, l, r));
}

int hq(int a) {
	// 구성된 체인 안에서 가장 작은 간선의 번호를 찾음
	// ==> 1에 가까워질수록 간선의 번호는 작아짐
	int ret = N;
	while (top[a] != top[1]) {
		int st = top[a];
		ret = min(ret, sq(1, 1, n, in[st], in[a]));
		a = par[st];
	}
	ret = min(ret, sq(1, 1, n, 1, in[a]));
	return ret == N ? -1 : vtx[ret];
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d\n", &n);
	std::fill(seg, seg + 4 * n + 1, N);
	for (int i = 1, a, b;i < n;++i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(); dfs2(); dfs3();
	scanf("%d\n", &q);
	int op, x;
	while (q--) {
		scanf("%d %d", &op, &x);
		if (op == 1) su(1, 1, n, in[x]);
		else printf("%d\n", hq(x));
	}
	return 0;
}

// 합 세그먼트 트리 + 이분 탐색을 통한 풀이
int n, q, sz[N], dep[N], par[N], in[N], top[N], pv, seg[N * 4], vtx[N];
std::vector<int> adj[N], g[N];
bool used[N];

void upd(int node, int s, int e, int idx) {
	if (idx < s || e < idx) return;
	if (s == e) {
		seg[node] = !seg[node];
		return;
	}
	int m = (s + e) >> 1;
	upd(node << 1, s, m, idx);
	upd(node << 1 | 1, m + 1, e, idx);
	seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

// sum 함수를 통해 검은 돌의 존재 여부를 확인
int sum(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[node];
	int m = (s + e) >> 1;
	return sum(node << 1, s, m, l, r) + sum(node << 1 | 1, m + 1, e, l, r);
}

int query_seg(int l, int r) {
	if (!sum(1, 1, n, l, r)) return -1;
	int ret = -1;
	// l과 가까울 수록, 즉 r이 줄어들 때 ret 갱신
	while (l <= r) {
		int m = l + r >> 1;
		if (sum(1, 1, n, l, m)) ret = m, r = m - 1;
		else l = m + 1;
	}
	return ret;
}

int query_hld(int a) {
	int ret = -1, cur;
	while (top[a] != top[1]) {
		int st = top[a];
		cur = query_seg(in[st], in[a]);
		if (cur > 0) ret = cur;
		a = par[st];
	}
	cur = query_seg(1, in[a]);
	if (cur > 0) ret = cur;
	return ret > 0 ? vtx[ret] : -1;
}

int solve_2() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 1, a, b;i < n;++i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs1(); dfs2(); dfs3();
	scanf("%d\n", &q);
	int op, x;
	while (q--) {
		scanf("%d %d", &op, &x);
		if (op == 1) upd(1, 1, n, in[x]);
		else printf("%d\n", query_hld(x));
	}
	return 0;
}