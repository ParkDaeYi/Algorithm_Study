#include <iostream>
using namespace std;

int n;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool visit[29][29];
double ewns[4];

double backtrack(int y, int x, int depth) {
	if (depth == n) return 1.0;
	double ret = 0.0;
	visit[y][x] = 1;
	for (int i = 0;i < 4;++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (visit[ny][nx]) continue;
		ret += ewns[i] * backtrack(ny, nx, depth + 1);
	}
	visit[y][x] = 0;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < 4;++i) cin >> ewns[i], ewns[i] /= 100.0;
	cout.precision(10);
	cout << fixed << backtrack(n, n, 0);
	return 0;
}