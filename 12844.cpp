#include <iostream>
#include <cmath>
#include <cstdio>
#define N 500001
#pragma warning(disable:4996)
using namespace std;

int n, m, seg[N * 4], lazy[N * 4];

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
	scanf("%d\n", &n);
	const int sz = pow(2, (int)log2(n - 1) + 1);
	for (int i = 0;i < n;++i) scanf("%d", seg + sz + i);
	for (int i = sz - 1;i >= 0;--i) seg[i] = seg[i * 2] ^ seg[i * 2 + 1];
	scanf("%d\n", &m);
	while (m--) {
		int op, a, b, c;
		scanf("%d %d %d", &op, &a, &b);
		if (a > b) swap(a, b);
		if (op == 1) {
			scanf("%d", &c);
			update_range(1, 0, sz - 1, a, b, c);
		}
		else printf("%d\n", query(1, 0, sz - 1, a, b));
	}
	return 0;
}
