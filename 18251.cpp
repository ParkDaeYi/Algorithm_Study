#include <stdio.h>
#pragma warning(disable:4996)
typedef long long ll;

int n, arr[1 << 18];
ll ans = -1e9, cur;

inline ll max(ll a, ll b) { return a < b ? b : a; }

// 중위 순회
void dfs(int i, int dep, int l, int r) {
	if (dep > r || i > n) return;
	dfs(i * 2, dep + 1, l, r);
	if (l <= dep) {
		cur = max(cur + arr[i], 0LL);
		ans = max(ans, cur);
	}
	dfs(i * 2 + 1, dep + 1, l, r);
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d\n", &n);
	for (int i = 1;i <= n;++i) {
		scanf("%d", arr + i);
		ans = max(ans, 1LL * arr[i]);
	}
	// 모든 정점의 가중치가 0 이하일 경우
	if (ans <= 0) {
		printf("%lld", ans);
		return 0;
	}
	// 깊이가 i와 j 에 속한 정점 중
	// 구할 수 있는 최대 가중치를 구함
	for (int i = 0;i < 18;++i) {
		for (int j = i;j < 18;++j) {
			cur = 0;
			dfs(1, 0, i, j);
		}
	}
	printf("%lld", ans);
	return 0;
}

// 미리 정점에 깊이를 매긴 후
#include <vector>
#include <algorithm>
using namespace std;

int n, id[1 << 18], pv;
struct Point {
	ll dep, w;
	Point(ll d, ll w) :dep(d), w(w) {}
};
vector<Point> v;

void dfs(int i = 1, int d = 0) {
	if (i * 2 <= n) dfs(i * 2, d + 1);
	id[i] = pv++;
	v.emplace_back(Point(d, 0));
	if (i * 2 + 1 <= n) dfs(i * 2 + 1, d + 1);
}

int solve_2() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d\n", &n);
	dfs();
	ll ans = -1e9;
	for (int i = 1;i <= n;++i) {
		ll x;
		scanf("%lld", &x);
		v[id[i]].w = x;
		ans = max(ans, x);
	}
	if (ans <= 0) {
		printf("%lld", ans);
		return 0;
	}
	ans = 0;
	for (int i = 0;i < 18;++i) {
		for (int j = i;j < 18;++j) {
			ll cur = 0, mx = 0;
			for (int k = 0;k < n;++k) {
				// 해당 범위에 속할 경우만 갱신
				if (v[k].dep<i || v[k].dep>j) continue;
				cur = max(0LL, v[k].w + cur);
				mx = max(mx, cur);
			}
			ans = max(ans, mx);
		}
	}
	printf("%lld", ans);
	return 0;
}