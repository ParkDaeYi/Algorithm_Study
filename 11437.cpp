// LCA 2 랑 소스 같음
#include <stdio.h>
#include <math.h>
#include <vector>
#define N 50001
#pragma warning(disable:4996)

const int ml = (int)floor(log2(N));
int n, q, dep[N], ac[N][16];
std::vector<int> g[N];

inline void swap(int& a, int& b) { int t = a;a = b;b = t; }

void mt(int c = 1, int p = 0) {
	dep[c] = dep[p] + 1;
	ac[c][0] = p;
	for (int i = 1, t;i <= ml;++i) {
		t = ac[c][i - 1];
		ac[c][i] = ac[t][i - 1];
	}
	for (int nt : g[c]) {
		if (nt != p) mt(nt, c);
	}
}

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	scanf("%d\n", &n);
	int a, b, lca;
	for (int i = 1;i < n;++i) {
		scanf("%d %d\n", &a, &b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	dep[0] = -1;
	mt();
	scanf("%d\n", &q);
	while (q--) {
		scanf("%d %d", &a, &b);
		if (dep[a] ^ dep[b]) {
			if (dep[a] > dep[b]) swap(a, b);
			for (int i = ml;i >= 0;--i) {
				if (dep[a] <= dep[ac[b][i]]) b = ac[b][i];
			}
		}
		lca = a;
		if (a ^ b) {
			for (int i = ml;i >= 0;--i) {
				if (ac[a][i] ^ ac[b][i]) {
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}
		printf("%d\n", lca);
	}
	return 0;
}