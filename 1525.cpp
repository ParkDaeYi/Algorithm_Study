#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<int, int> umap;
int dest = 123456780, p[3][3], src, ans = -1;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int encode();
void decode(int);
void zero(int&, int&);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cin >> p[i][j];
	src = encode();
	queue<int> q;
	q.push(src);
	umap[src] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == dest) break;
		decode(cur);
		int y, x;
		zero(y, x);
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny>2 || nx>2) continue;
			swap(p[y][x], p[ny][nx]);
			int next = encode();
			if (!umap.count(next)) {
				umap[next] = umap[cur] + 1;
				q.push(next);
			}
			swap(p[y][x], p[ny][nx]);
		}
	}
	umap.count(dest) ? cout << umap[dest] - 1 : cout << -1;
	return 0;
}

int encode() {
	int ret = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			ret *= 10;
			ret += p[i][j];
		}
	}
	return ret;
}

void decode(int cur) {
	for (int i = 2; i >= 0; --i) {
		for (int j = 2; j >= 0; --j) {
			p[i][j] = cur % 10;
			cur /= 10;
		}
	}
}

void zero(int& y, int& x) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (!p[i][j]) {
				y = i;
				x = j;
				return;
			}
		}
	}
}