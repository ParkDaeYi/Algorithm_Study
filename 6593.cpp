#include <iostream>
#include <queue>
using namespace std;

class se {
public:
	int z, y, x;
	se(int z = -1, int y = -1, int x = -1) :z(z), y(y), x(x) {}
};
se s, e;
int L, R, C, cache[30][30][30];
bool bui[30][30][30];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (1) {
		cin >> L >> R >> C;
		if (!L && !R && !C) return 0;
		int cache[30][30][30] = { 0, };
		bool bui[30][30][30] = { 0, };
		for (int i = 0; i < L; ++i) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k) {
					char tmp;
					cin >> tmp;
					if (tmp == '#') {
						bui[i][j][k] = 1; continue;
					}
					if (tmp == 'S') s = se(i, j, k);
					if (tmp == 'E') e = se(i, j, k);
				}
			}
		}
		queue<se> q;
		q.push(s);
		cache[s.z][s.y][s.x] = 1;
		while (!q.empty()) {
			int z = q.front().z, y = q.front().y, x = q.front().x;
			q.pop();
			if (z == e.z && y == e.y && x == e.x) break;
			for (int i = 0; i < 6; ++i) {
				int nz = z + dz[i], ny = y + dy[i], nx = x + dx[i];
				if (nz < 0 || ny < 0 || nx < 0 || nz >= L || ny >= R || nx >= C) continue;
				if (cache[nz][ny][nx] || bui[nz][ny][nx]) continue;
				q.push(se(nz, ny, nx));
				cache[nz][ny][nx] = cache[z][y][x] + 1;
			}
		}
		cache[e.z][e.y][e.x] ? cout << "Escaped in " << cache[e.z][e.y][e.x] - 1 << " minute(s).\n" : cout << "Trapped!\n";
	}
}