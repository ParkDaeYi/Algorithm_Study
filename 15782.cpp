#include <iostream>
#include <cstdio>
#include <vector>
#define N 100001
#pragma warning(disable:4996)
using namespace std;

int n, m, arr[N], cnt[N], child[N], order[N], sz, seg[N * 4], lazy[N * 4];
// cnt: 현재 정점 + 자식 개수, child: 자식
vector<int> adj[N];
bool used[N];

int range(int idx) {
	used[idx] = 1;
	int ch = 0;
	for (int nxt : adj[idx]) {
		if (used[nxt]) continue;
		ch += range(nxt);
	}
	cnt[idx] = ++sz;
	child[idx] = ch;
	order[sz] = arr[idx];
	return ch + 1;
}

void init(int node, int start, int end) {
	if (start == end) {
		seg[node] = order[start];
		return;
	}
	int mid = (start + end) >> 1;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

void update_lazy(int node, int start, int end) {
	if (!lazy[node]) return;
	seg[node] ^= ((end - start + 1) % 2) * lazy[node];
	if (start != end) {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2 + 1] ^= lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, int val) {
	update_lazy(node, start, end);
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		seg[node] ^= ((end - start + 1) % 2) * val;
		if (start != end) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}
	int mid = (start + end) >> 1;
	update_range(node * 2, start, mid, left, right, val);
	update_range(node * 2 + 1, mid + 1, end, left, right, val);
	seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) >> 1;
	return query(node * 2, start, mid, left, right) ^ query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d %d\n", &n, &m);
	for (int i = 1, a, b;i < n;++i) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1;i <= n;++i) scanf("%d", arr + i);
	range(1);
	init(1, 1, n);
	int a, b, c;
	while (m--) {
		scanf("%d %d", &a, &b);
		if (a == 1) printf("%d\n", query(1, 1, n, cnt[b] - child[b], cnt[b]));
		else {
			scanf(" %d", &c);
			update_range(1, 1, n, cnt[b] - child[b], cnt[b], c);
		}
	}
	return 0;
}
