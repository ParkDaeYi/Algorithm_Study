#include <iostream>
#include <algorithm>
#define MAX 1e9+1
using namespace std;

int dist[16][16], n, cache[16][1 << 16];

int TSP(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> dist[i][j];
	cout << TSP(0, 1);
	return 0;
}

int TSP(int here, int visited) {
	if (visited == (1 << n) - 1) {
		if (dist[here][0]) return dist[here][0];
		else return MAX;
	}
	int& ret = cache[here][visited];
	if (ret) return ret;
	ret = MAX;
	for (int next = 1; next < n; ++next) {
		if (visited & (1 << next)) continue;
		if (!dist[here][next]) continue;
		ret = min(ret, TSP(next, visited | (1 << next)) + dist[here][next]);
	}
	return ret;
}
