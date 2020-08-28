// Online Query 방식
#include <stdio.h>
#include <vector>
#include <algorithm>
#define N 100001
#pragma warning(disable:4996)

int n, q, arr[N];
std::vector<int> tree[N * 4];

int upper(std::vector<int>& v, int l, int r, int t) {
	while (l < r) {
		int m = (l + r) >> 1;
		if (v[m] <= t) l = m + 1;
		else r = m;
	}
	return r;
}

void upd(int node, int s, int e, int p, int v) {
	if (p < s || e < p) return;
	tree[node].emplace_back(v);
	if (s ^ e) {
		int m = (s + e) >> 1;
		upd(node << 1, s, m, p, v);
		upd(node << 1 | 1, m + 1, e, p, v);
	}
}

int query(int node, int s, int e, int l, int r, int k) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return tree[node].size() - upper(tree[node], 0, tree[node].size(), k);
	}
	int m = (s + e) >> 1;
	return query(node << 1, s, m, l, r, k) + query(node << 1 | 1, m + 1, e, l, r, k);
}

int main() {
	scanf("%d\n", &n);
	for (int i = 1;i <= n;++i) {
		scanf("%d", arr + i);
		upd(1, 1, n, i, arr[i]);
	}

	for (int i = 1;i < n * 2;++i) std::sort(tree[i].begin(), tree[i].end());

	scanf("%d\n", &q);
	while (q--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("%d\n", query(1, 1, n, a, b, c));
	}
	return 0;
}

// Offline Query 방식
#include <math.h>

struct Query {
	// type==1 값을 삽입하는 쿼리
	// type==2 해를 구하는 쿼리
	int type, idx, i, j, k;
};
int n, q, sz, seg[1 << 18], ans[100001];
std::vector<Query> queries;

int sum(int l, int r) {
	int ret = 0;
	/*
				A(1)
		B(2)			C(3)
	D(4)	E(5)	F(6)	G(7)
	라고 가정, (i) ==> 인덱스 번호
	l % 2 가 1일 때
	 - ex.	 l이 E(5)+sz(4) = 9 라고 가정
			l 은 E만 확인하고 F와 G의 정보를 가지고 있는 C로 넘어가면 됨
			D(4)는 범위에 속하지 않으므로 B(2)를 볼 필요가 없음

	r % 2 가 0 일 때
	 - 위와 같은 맥락
	*/
	for (l += sz, r += sz;l <= r;l /= 2, r /= 2) {
		if (l % 2) ret += seg[l++];	
		if (r % 2 == 0) ret += seg[r--];	
	}
	return ret;
}

int offline_query() {
	scanf("%d\n", &n);
	sz = 1 << ((int)log2(n - 1) + 1);
	for (int i = 0, x;i < n;++i) {
		scanf("%d", &x);
		queries.push_back({ 1,i,0,0,x });
	}
	scanf("%d\n", &q);
	for (int i = 0, a, b, c;i < q;++i) {
		scanf("%d %d %d", &a, &b, &c);
		queries.push_back({ 2,i,--a,--b,c });
	}
	// 1. 삽입해야하는 값 혹은 해를 구해야 하는 값이 큰 순서로
	// 2. 값이 같다면 해를 구하는 쿼리가 먼저 오도록
	// ==> 해를 구할 때는 k 의 값보다 작거나 같은 값들은 신경 쓸 필요가 없음
	std::sort(queries.begin(), queries.end(), [&](Query a, Query b) {
		return a.k != b.k ? a.k > b.k:a.type > b.type;
		});
	for (Query q : queries) {
		if (q.type == 1) for (int node = q.idx + sz;node > 0;node /= 2) seg[node] += 1;
		else ans[q.idx] = sum(q.i, q.j);
	}
	for (int i = 0;i < q;++i) printf("%d\n", ans[i]);
	return 0;
}