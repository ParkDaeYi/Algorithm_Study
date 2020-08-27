// solve-1
#include <iostream>
#include <cstdio>
#define N 100001
#pragma warning(disable:4996)
using namespace std;
#define v first
#define c second
typedef long long ll;
typedef pair<ll, ll> pll;

int n, m;
ll arr[N];
pll seg[1 << 18];

void init(int node, int s, int e) {
	if (s == e) {
		seg[node].v = arr[s];
		return;
	}
	int mid = (s + e) >> 1;
	init(node << 1, s, mid);
	init(node << 1 | 1, mid + 1, e);
}

void upt(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		// 해당 범위에 대한 최소한의 값만 업데이트
		// ==> 해당 범위에서 처음으로 더해지는 수
		//	ex. [2, 4] 라고 가정
		//		2는 리프노드에 1이 추가 되지만
		//		[3, 4]의 경우 부모노드에 2가 추가 됨
		seg[node].v += s - l + 1;
		// query문에서 사용
		seg[node].c++;
		return;
	}
	int mid = (s + e) >> 1;
	upt(node << 1, s, mid, l, r);
	upt(node << 1 | 1, mid + 1, e, l, r);
}

ll query(int node, int s, int e, int t) {
	if (t < s || e < t) return 0;
	if (s == e) return seg[node].v;
	int mid = (s + e) >> 1;
	// query 좌우를 통해서 값을 넘겨 받음
	// seg[node].v 에서 처음 더해지는 숫자를 더하고
	// seg[node].c * (target - start) 를 통해 수를 추가함
	return query(node << 1, s, mid, t) + query(node << 1 | 1, mid + 1, e, t)
		+ seg[node].v + seg[node].c * (t - s);
}

int main() {
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	scanf("%d\n", &n);
	for (int i = 1;i <= n;++i) scanf("%d", &arr[i]);
	init(1, 1, n);
	scanf("%d\n", &m);
	while (m--) {
		int op, a, b;
		scanf("%d %d", &op, &a);
		if (op == 1) {
			scanf(" %d", &b);
			upt(1, 1, n, a, b);
		}
		else printf("%lld\n", query(1, 1, n, a));
	}
	return 0;
}

// solve-2
int n, m;
ll v[N], diff[N], tree[1 << 18], lazy[1 << 18];

// 등차수열을 이용한 풀이
// 등차수열: 첫째항에 일정한 수를 더해서 얻어진 항으로 이루어진 수열
// 공차(d): 각 항에 더해지는 일정한 수
// a[n] = a[n - 1] + d
// d = a[n] - a[n - 1] ==> 이 공식을 사용

ll init_2(int node, int s, int e) {
	if (s == e) return tree[node] = diff[s];
	int mid = (s + e) >> 1;
	return tree[node] = init_2(node << 1, s, mid) + init_2(node << 1 | 1, mid + 1, e);
}

void update_lazy(int node, int s, int e) {
	if (!lazy[node]) return;
	tree[node] += (e - s + 1) * lazy[node];
	if (s ^ e) {
		lazy[node << 1] += lazy[node];
		lazy[node << 1 | 1] += lazy[node];
	}
	lazy[node] = 0;
}

ll update_range(int node, int s, int e, int l, int r, int v) {
	update_lazy(node, s, e);
	if (r < s || e < l) return tree[node];
	if (l <= s && e <= r) {
		lazy[node] = v;
		update_lazy(node, s, e);
		return tree[node];
	}
	int mid = (s + e) >> 1;
	return tree[node] = update_range(node << 1, s, mid, l, r, v) + update_range(node << 1 | 1, mid + 1, e, l, r, v);
}

ll query(int node, int s, int e, int l, int r) {
	update_lazy(node, s, e);
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return tree[node];
	int mid = (s + e) >> 1;
	return query(node << 1, s, mid, l, r) + query(node << 1 | 1, mid + 1, e, l, r);
}

int solve_1() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);

	scanf("%d\n", &n);
	// 1. diff[i] = v[i] - v[i - 1]
	//	여기서 x는 1부터 x까지의 구간 합으로 구할 수 있다
	//	(v[1]-v[0])+(v[2]-v[1])+...+(v[x]-v[x-1])
	//	= v[x] - v[0] = v[x] 이기 때문이다
	for (int i = 1;i <= n;++i) {
		scanf("%d", &v[i]);
		diff[i] = v[i] - v[i - 1];
	}
	init_2(1, 1, n);
	scanf("%d\n", &m);
	while (m--) {
		int op, a, b;
		scanf("%d %d", &op, &a);
		if (op == 1) {
			scanf(" %d", &b);
			// 구간 [a, b]에 1을 증가시키고
			update_range(1, 1, n, a, b, 1);
			// [b+1, b+1]에는 구간의 길이(e - s + 1)을 뺀다
			//	==> b+1의 값을 구하려면 1부터 b+1까지 더해줘야 하는데
			//		구간 [a, b]는 이미 1을 증가 시켰기 때문에 b+1 구간은 빼준다
			update_range(1, 1, n, b + 1, b + 1, -(b - a + 1));
		}
		else printf("%lld\n", query(1, 1, n, 1, a));
	}
	return 0;
}