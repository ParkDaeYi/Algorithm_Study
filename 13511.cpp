#include <stdio.h>
#include <math.h>
#include <vector>
#define N 100001
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;

const int ml = (int)floor(log2(N));
int n, q, ac[N][20], dep[N];
ll dist[N];
vector <pil> g[N];

void mt(int now, int par, ll v) {
	dep[now] = dep[par] + 1;
	dist[now] = dist[par] + v;
	ac[now][0] = par;
	for (int i = 1;i <= ml;++i) {
		int tmp = ac[now][i - 1];
		ac[now][i] = ac[tmp][i - 1];
	}
	for (pil& nxt : g[now]) {
		if (nxt.first ^ par) mt(nxt.first, now, nxt.second);
	}
}

int gl(int u, int v) {
	if (dep[u] ^ dep[v]) {
		if (dep[u] > dep[v]) swap(u, v);
		for (int i = ml;i >= 0;--i) {
			if (dep[u] <= dep[ac[v][i]]) v = ac[v][i];
		}
	}
	int lca = u;
	if (u ^ v) {
		for (int i = ml;i >= 0;--i) {
			if (ac[u][i] ^ ac[v][i]) {
				u = ac[u][i];
				v = ac[v][i];
			}
			lca = ac[u][i];
		}
	}
	return lca;
}

int main() {
	scanf("%d\n", &n);
	int op, u, v, k;
	for (int i = 1;i < n;++i) {
		scanf("%d %d %d\n", &u, &v, &k);
		g[u].emplace_back(pil(v, k));
		g[v].emplace_back(pil(u, k));
	}
	mt(1, 0, 0);
	scanf("%d\n", &q);
	while (q--) {
		scanf("%d %d %d", &op, &u, &v);
		int lca = gl(u, v);
		// dist[u] 는 u에서 루트 1까지의 거리 값을 가지고 있음
		// 그러므로 거리 계산을 할 때 u와 v의 lca를 꼭 빼줘야함
		if (op == 1) printf("%lld\n", dist[u] + dist[v] - 2 * dist[lca]);
		else {
			scanf(" %d", &k);
			// diff는 경우의 수라고 생각하면 된다
			// u 에서 lca 사이에서 u를 제외한 정점의 개수이다.
			int diff = dep[u] - dep[lca];
			k--;
			if (diff >= k) {
				for (int i = 0;k;++i) {
					if (k & 1) u = ac[u][i];
					k >>= 1;
				}
				printf("%d\n", u);
			}
			else {
				// k가 diff보다 클 경우
				// v에서 시작해야 하므로
				// k 값을 재지정한다.
				k = dep[v] - dep[lca] + diff - k;
				for (int i = 0;k;++i) {
					if (k & 1) v = ac[v][i];
					k >>= 1;
				}
				printf("%d\n", v);
			}
		}
	}
	return 0;
}