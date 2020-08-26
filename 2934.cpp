#include <iostream>
#include <cstdio>
#define N 100001
#pragma warning(disable:4996)
using namespace std;

int n, seg[N * 4], lazy[N * 4];

void update_lazy(int node, int start, int end) {
	if (!lazy[node]) return;
	seg[node] += lazy[node] * (end - start + 1);
	if (start != end) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}

void update_range(int node, int start, int end, int left, int right, int val) {
	update_lazy(node, start, end);
	if (right < start || end < left) return;
	if (left <= start && end <= right) {
		seg[node] += val * (end - start + 1);
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (start + end) >> 1;
	update_range(node * 2, start, mid, left, right, val);
	update_range(node * 2 + 1, mid + 1, end, left, right, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

int query(int node, int start, int end, int left, int right) {
	update_lazy(node, start, end);
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) >> 1;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 0, x, y;i < n;++i) {
		scanf("%d %d", &x, &y);
		int a = query(1, 1, N, x, x), b = query(1, 1, N, y, y);
		printf("%d\n", a + b);
		if (a) update_range(1, 1, N, x, x, -a);
		if (b) update_range(1, 1, N, y, y, -b);
		if (++x > --y) continue;
		update_range(1, 1, N, x, y, 1);
	}
	return 0;
}

// 펜윅트리 공부하면 추가하겠음