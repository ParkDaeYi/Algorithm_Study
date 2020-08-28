#include <stdio.h>
#define N 65536
#pragma warning(disable:4996)
typedef long long ll;

int n, k, arr[250001];
ll seg[N * 4], ans;

ll upd(int node, int s, int e, int p, int v) {
	if (p < s || e < p) return seg[node];
	if (s == e) return seg[node] += v;
	int m = (s + e) >> 1;
	return seg[node] = upd(node << 1, s, m, p, v) + upd(node << 1 | 1, m + 1, e, p, v);
}

ll query(int node, int s, int e, ll p) {
	if (s == e) return s;
	int m = (s + e) >> 1;
	if (seg[node << 1] >= p) return query(node << 1, s, m, p);
	return query(node << 1 | 1, m + 1, e, p - seg[node << 1]);
}

int main() {
	scanf("%d %d\n", &n, &k);
	for (int i = 0;i < n;++i) scanf("%d", arr + i);
	for (int i = 0;i < k - 1;++i) upd(1, 0, N - 1, arr[i], 1);
	for (int i = k - 1;i < n;++i) {
		upd(1, 0, N - 1, arr[i], 1);
		ans += query(1, 0, N - 1, (k + 1) >> 1);
		upd(1, 0, N - 1, arr[i - k + 1], -1);
	}
	printf("%lld", ans);
	return 0;
}