#include <iostream>
#include <algorithm>
#define MAX_V 10001
#define MAX_E 100001
using namespace std;

class edge {
public:
	int f, t, c;
}graph[MAX_E];
int v, e, ans, parent[MAX_V];

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	for (int i = 1;i < v + 1;++i) parent[i] = i;
	for (int i = 0;i < e;++i) cin >> graph[i].f >> graph[i].t >> graph[i].c;
	sort(graph, graph + e,[](const edge& e1, const edge& e2) {
		return e1.c < e2.c;
	});
	for (int i = 0;i < e;++i) {
		int from = graph[i].f, to = graph[i].t;
		from = getParent(from);
		to = getParent(to);
		if (from == to) continue;
		ans += graph[i].c;
		if (from < to) parent[from] = to;
		else parent[to] = from;
	}
	cout << ans;
	return 0;
}