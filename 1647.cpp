#include <iostream>
#include <algorithm>
#define MAXNODE 100001
#define MAXEDGE 1000001
using namespace std;

class E {
public:
	int cost, from, to;
	bool operator<(const E& e) const {
		return cost < e.cost;
	}
};
int v, e, parent[MAXNODE], ans, cnt;
E edge[MAXEDGE];

int getParent(int);
void unite(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v >> e;
	for (int i = 0; i < e; ++i) cin >> edge[i].from >> edge[i].to >> edge[i].cost;
	sort(edge, edge + e);
	for (int i = 1; i <= v; ++i) parent[i] = i;
	for (int i = 0; cnt < v - 2; ++i) {
		if (getParent(edge[i].from) != getParent(edge[i].to)) {
			unite(edge[i].from, edge[i].to);
			cnt++;
			ans += edge[i].cost;
		}
	}
	cout << ans;
	return 0;
}

int getParent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = getParent(parent[x]);
}

void unite(int x, int y) {
	x = parent[x];
	y = parent[y];
	parent[x] = y;
}