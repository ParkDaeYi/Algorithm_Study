#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_VERTEX 100000
using namespace std;
typedef pair<int, pair<int, int>> pipii;
typedef pair<int, int> pii;

class planet {
public:
	int x, y, z, idx;
};
bool cmp_x(const planet& p1, const planet& p2) {
	return p1.x < p2.x;
}
bool cmp_y(const planet& p1, const planet& p2) {
	return p1.y < p2.y;
}
bool cmp_z(const planet& p1, const planet& p2) {
	return p1.z < p2.z;
}

int v, parent[MAX_VERTEX], ans;
vector<pipii> graph;
planet plt[MAX_VERTEX];

int getParent(int);
void unite(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> v;
	for (int i = 0; i < v; ++i) {
		cin >> plt[i].x >> plt[i].y >> plt[i].z;
		plt[i].idx = i;
		parent[i] = i;
	}
	sort(plt, plt + v, cmp_x);
	for (int i = 1; i < v; ++i) graph.push_back(pipii(plt[i].x - plt[i - 1].x, pii(plt[i].idx, plt[i - 1].idx)));
	sort(plt, plt + v, cmp_y);
	for (int i = 1; i < v; ++i) graph.push_back(pipii(plt[i].y - plt[i - 1].y, pii(plt[i].idx, plt[i - 1].idx)));
	sort(plt, plt + v, cmp_z);
	for (int i = 1; i < v; ++i) graph.push_back(pipii(plt[i].z - plt[i - 1].z, pii(plt[i].idx, plt[i - 1].idx)));
	sort(graph.begin(), graph.end());
	for (int i = 0, cnt = 0; cnt < v - 1; ++i) {
		if (getParent(graph[i].second.first) != getParent(graph[i].second.second)) {
			unite(graph[i].second.first, graph[i].second.second);
			cnt++;
			ans += graph[i].first;
		}
	}
	cout << ans;
	return 0;
}

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unite(int a, int b) {
	parent[parent[a]] = parent[b];
}