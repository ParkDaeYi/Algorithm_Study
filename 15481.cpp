#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define N 200001
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
typedef pair<int, ll> pil;

const int ml = (int)floor(log2(N));
int n, q, dep[N], ac[N][20], dist[N][20], par[N];
vector<pil> g[N];
struct Query {
	int u, v, w;
	bool operator<(const Query& q) const {
		return w < q.w;
	}
};
vector<Query> edge;

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return 0;
	return par[a] = b;
}

ll mst() {
	vector<Query> v = edge;
	sort(v.begin(), v.end());
	for (int i = 1;i <= n;++i) par[i] = i;
	ll ret = 0;
	for (Query& i : v) {
		if (merge(i.u, i.v)) {
			ret += i.w;
			g[i.u].push_back({ i.v,i.w });
			g[i.v].push_back({ i.u,i.w });
		}
	}
	return ret;
}

// make_tree
void mt(int now, int par, ll v) {
	dep[now] = dep[par] + 1;
	ac[now][0] = par;
	dist[now][0] = v;
	for (int i = 1;i <= ml;++i) {
		int tmp = ac[now][i - 1];
		ac[now][i] = ac[tmp][i - 1];
		dist[now][i] = max(dist[now][i - 1], dist[tmp][i - 1]);
	}
	for (pil& nxt : g[now]) {
		if (nxt.first ^ par) mt(nxt.first, now, nxt.second);
	}
}

// get_lca
int gl(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	int diff = dep[a] - dep[b];
	for (int i = 0;diff;++i) {
		if (diff & 1) a = ac[a][i];
		diff >>= 1;
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
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for (int i = 0, u, v, w;i < q;++i) {
		cin >> u >> v >> w;
		edge.push_back({ u,v,w });
	}
	// 우선적으로 mst를 완성시킴
	ll ret = mst();
	// 그 후 mst에서 사용된 간선을 이용하여
	// lca를 구현한다
	// dist의 경우 가장 큰 값을 저장하는데
	// u와 v 사이에서 가장 값이 큰 간선을 빼고 새로운 간선을 추가하면
	// 새로운 mst의 값을 알 수 있기 때문이다
	mt(1, 0, 0);
	// ex.
	//		2		4		1		3
	//	1 -----	3 -----	2 -----	5 -----	4
	// 여기에서 만약 1 과 5을 연결하는 새로운 간선을 추가할 때
	// 4를 빼주고 새 간선을 추가하면 되기 때문임

	for (Query& i : edge) {
		int u = i.u, v = i.v, w = i.w, lca = gl(i.u, i.v);
		ll ans = ret;
		int mx = 0, diff = dep[u] - dep[lca];
		// u 에서 lca 까지
		for (int i = 0;diff;++i) {
			if (diff & 1) mx = max(mx, dist[u][i]), u = ac[u][i];
			diff >>= 1;
		}
		diff = dep[v] - dep[lca];
		// v 에서 lca 까지
		for (int i = 0;diff;++i) {
			if (diff & 1) mx = max(mx, dist[v][i]), v = ac[v][i];
			diff >>= 1;
		}
		cout << ans - mx + w << '\n';
	}
	return 0;
}