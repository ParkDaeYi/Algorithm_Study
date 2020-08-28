// 머지 소트 트리
#include <stdio.h>
#include <vector>
#define N 100001
using namespace std;

int n, q, ans;
vector<int> seg[N * 4];

// query 받기 전 초기 설정
void merge(vector<int>& a, vector<int>& b, vector<int>& c) {
	int l = 0, r = 0, bsz = b.size(), csz = c.size();
	while (l < bsz && r < csz) {
		if (b[l] < c[r]) a.push_back(b[l++]);
		else a.push_back(c[r++]);
	}
	while (l < bsz) a.push_back(b[l++]);
	while (r < csz) a.push_back(c[r++]);
}

int upper(vector<int>& v, int l, int r, int k) {
	while (l < r) {
		int m = (l + r) >> 1;
		if (v[m] <= k) l = m + 1;
		else r = m;
	}
	return r;
}

int query(int l, int r, int k) {
	int ret = 0;
	for (l += n, r += n;l <= r;l >>= 1, r >>= 1) {
		if (l % 2) {
			ret += seg[l].size() - upper(seg[l], 0, seg[l].size(), k);
			l++;
		}
		if (r % 2 == 0) {
			ret += seg[r].size() - upper(seg[r], 0, seg[r].size(), k);
			r--;
		}
	}
	return ret;
}

int main() {
	scanf("%d\n", &n);
	for (int i = 0, x;i < n;++i) {
		scanf("%d", &x);
		seg[i + n].push_back(x);
	}
	for (int i = n - 1;i > 0;--i) merge(seg[i], seg[i << 1], seg[i << 1 | 1]);
	scanf("%d\n", &q);
	int a, b, c;
	while (q--) {
		scanf("%d %d %d", &a, &b, &c);
		a ^= ans, b ^= ans, c ^= ans;
		printf("%d\n", ans = query(--a, --b, c));
	}
	return 0;
}

// 세그먼트 트리로 머지 소트 트리 흉내냄(더 느림)
#include <algorithm>

int n, q, ans;
std::vector<int> seg[N * 4];

void init(int node, int s, int e, int idx, int v) {
	if (idx < s || e < idx) return;
	seg[node].push_back(v);
	if (s ^ e) {
		int m = (s + e) >> 1;
		init(node << 1, s, m, idx, v);
		init(node << 1 | 1, m + 1, e, idx, v);
	}
}

int query_2(int node, int s, int e, int l, int r, int k) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[node].size() - upper(seg[node], 0, seg[node].size(), k);
	int m = (s + e) >> 1;
	return query_2(node << 1, s, m, l, r, k) + query_2(node << 1 | 1, m + 1, e, l, r, k);
}

int solve_2() {
	scanf("%d\n", &n);
	for (int i = 1, x;i <= n;++i) {
		scanf("%d", &x);
		init(1, 1, n, i, x);
	}
	for (int i = 1;i < n * 2;++i) std::sort(seg[i].begin(), seg[i].end());
	scanf("%d\n", &q);
	int a, b, c;
	while (q--) {
		scanf("%d %d %d", &a, &b, &c);
		a ^= ans, b ^= ans, c ^= ans;
		ans = query_2(1, 1, n, a, b, c);
		printf("%d\n", ans);
	}
	return 0;
}