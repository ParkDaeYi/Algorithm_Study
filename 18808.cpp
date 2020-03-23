#include <stdio.h>
#pragma warning (disable:4996)

int n, m, r, c, k, mp[41][41], pp[11][11];

void rotate() {
	int tmp[11][11];
	for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) tmp[i][j] = pp[i][j];
	for (int i = 0; i < c; ++i) for (int j = 0; j < r; ++j) pp[i][j] = tmp[r - j - 1][i];
	int t = r;
	r = c;
	c = t;
}

bool chk(int y, int x) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (mp[y + i][x + j] && pp[i][j]) return 0;
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (pp[i][j]) mp[y + i][x + j] = 1;
		}
	}
	return 1;
}

int main() {

	scanf("%d %d %d\n", &n, &m, &k);
	while (k--) {
		scanf("%d %d", &r, &c);
		for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) scanf("%d", &pp[i][j]);
		for (int i = 0; i < 4; ++i) {
			bool flag = 0;
			for (int y = 0; y <= n - r; ++y) {
				for (int x = 0; x <= m - c; ++x) {
					if (chk(y, x)) {
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
			rotate();
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (mp[i][j]) cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}