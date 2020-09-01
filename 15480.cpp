#include <stdio.h>
#include <math.h>
#include <vector>
#define N 100001
#pragma warning(disable:4996)

const int ml = (int)floor(log2(N));
int n, q, dep[N], ac[N][20];
std::vector<int> g[N];

inline int max(int a, int b) { return a < b ? b : a; }
inline void swap(int& a, int& b) { int t = a;a = b;b = t; }

void mt(int now, int par) {
	dep[now] = dep[par] + 1;
	ac[now][0] = par;
	for (int i = 1;i <= ml;++i) {
		int tmp = ac[now][i - 1];
		ac[now][i] = ac[tmp][i - 1];
	}
	for (int& nxt : g[now]) {
		if (nxt ^ par) mt(nxt, now);
	}
}

int gl(int a, int b) {
	if (dep[a] ^ dep[b]) {
		if (dep[a] > dep[b]) swap(a, b);
		for (int i = ml;i >= 0;--i) {
			if (dep[a] <= dep[ac[b][i]]) b = ac[b][i];
		}
	}
	int lca = a;
	if (a ^ b) {
		for (int i = ml;i >= 0;--i) {
			if (ac[a][i] ^ ac[b][i]) {
				a = ac[a][i];
				b = ac[b][i];
			}
			lca = ac[a][i];
		}
	}
	return lca;
}

int main() {
	scanf("%d\n", &n);
	int r, a, b;
	for (int i = 1;i < n;++i) {
		scanf("%d %d\n", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	mt(1, 0);
	scanf("%d\n", &q);
	while (q--) {
		scanf("%d %d %d", &r, &a, &b);
		// 힌트가 얼마 없어서 해봣는데 맞음;;;;;;
		// 왜 맞는지는 대강은 알겟는데 설명은 못하겠음;;
		int l1 = gl(a, b), l2 = gl(r, a), l3 = gl(r, b);
		int ans = l1;
		if (dep[ans] < dep[l2]) ans = l2;
		if (dep[ans] < dep[l3]) ans = l3;
		printf("%d\n", ans);
	}
	return 0;
}