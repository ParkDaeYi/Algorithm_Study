#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define MAX_N 2002
#define MOD 1000000007
using namespace std;
typedef pair<int, int> pii;
typedef long long int llt;

int n, m, S, E;
bool visited[MAX_N];
llt pw[MAX_N], ans;
vector<llt> adj[MAX_N];
vector<pii> edge;

bool dfs(int here) {
	visited[here] = 1;
	if (here == E) return 1;
	bool ret = 0;
	for (int nxt : adj[here]) {
		if (visited[nxt]) continue;
		ret |= dfs(nxt);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	E = n - 1;
	for (int i = 0, u, v; i < m; ++i) {
		cin >> u >> v;
		edge.push_back({ u,v });
		if (i) pw[i] = (pw[i - 1] * 3) % MOD;
		else pw[i] = 1;
	}
	for (int i = m - 1; i >= 0; --i) {
		fill(visited, visited + n, 0);
		adj[edge[i].first].push_back(edge[i].second);
		adj[edge[i].second].push_back(edge[i].first);
		if (dfs(S)) {
			adj[edge[i].first].pop_back();
			adj[edge[i].second].pop_back();
			ans = (ans + pw[i]) % MOD;
		}
	}
	cout << ans;
	return 0;
}

// 기존 네트워크플로우로 접근할 시 3^i 를 전부 표현하지 못함
// 그러므로 제일 큰 수를 가진 edge부터 시작해서 제일 작은 edge로 접근
// 도중에 S와 E가 이어지면 ans 갱신, 마지막으로 연결된 부분 삭제 => 이미 한도까지 인원이 도로를 통과함