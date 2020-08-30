#include <stdio.h>
#include <algorithm>
#define N 200001
#define MOD 1000000007
#pragma warning(disable:4996)
typedef std::pair<int, int> pii;
typedef long long ll;

int n, seg[N * 8];
pii pos[N];

void su(int node, int s, int e, int i, int v) {
	if (i < s || e < i) return;
	if (s == e) {
		seg[node] += v;
		return;
	}
	int m = s + e >> 1;
	su(node << 1, s, m, i, v);
	su(node << 1 | 1, m + 1, e, i, v);
	seg[node] = seg[node << 1] + seg[node << 1 | 1];
}

ll sq(int node, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) 
		return 1LL * seg[node];
	int m = (s + e) >> 1;
	return sq(node << 1, s, m, l, r) + sq(node << 1 | 1, m + 1, e, l, r);
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 0;i < n;++i) {
		scanf("%d %d", &pos[i].second, &pos[i].first);
		su(1, 1, N * 2 - 1, pos[i].second + N, 1);
	}
	std::sort(pos, pos + n, [&](pii& a, pii& b) {
		return a.first != b.first ? a.first < b.first : a.second < b.second;
		});
	int y = -1;
	ll ans = 0;
	for (int i = 0;i < n;++i) {
		// y 좌표가 다를 경우 그냥 빼주고 연산하면 끝
		if (y ^ pos[i].first) {
			y = pos[i].first;
			for (int j = i;pos[j].first == y;++j) su(1, 1, N * 2 - 1, pos[j].second + N, -1);
		}
		ll l = sq(1, 1, N * 2 - 1, 0, pos[i].second + N - 1) % MOD;
		ll r = sq(1, 1, N * 2 - 1, pos[i].second + N + 1, N * 2 - 1) % MOD;
		ans = (ans + (l * r) % MOD) % MOD;
	}
	printf("%lld", ans);
	return 0;
}