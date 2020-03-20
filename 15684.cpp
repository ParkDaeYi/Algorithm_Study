#include <stdio.h>
#pragma warning(disable:4996)

int n, m, h, ans = 4;
bool visit[31][11], flag;

bool chk() {
	for (int i = 1; i <= n; ++i) {
		int cur = i;
		for (int j = 1; j <= h; ++j) {
			if (visit[j][cur]) cur++;
			else if (visit[j][cur - 1]) cur--;
		}
		if (cur != i) return 0;
	}
	return 1;
}

void simul(int cnt, int val) {
	if (cnt == val) {
		if (chk()) flag = 1;
		return;
	}
	for (int j = 1; j < n; ++j) {
		for (int i = 1; i <= h; ++i) {
			if (visit[i][j] || visit[i][j - 1] || visit[i][j + 1]) continue;
			visit[i][j] = 1;
			simul(cnt + 1, val);
			visit[i][j] = 0;
			while (i < h) {
				if (visit[i + 1][j - 1] || visit[i + 1][j + 1]) break;
				++i;
			}
		}
	}
}

int main() {
	//freopen("p679.inp", "r", stdin);
	//freopen("p679.out", "w", stdout);

	scanf("%d %d %d", &n, &m, &h);
	for (int i = 0, a, b; i < m; ++i) {
		scanf("%d %d", &a, &b);
		visit[a][b] = 1;
	}
	for (int i = 0; i < 4; ++i) {
		simul(0, i);
		if (flag) {
			ans = i;
			break;
		}
	}
	printf("%d", ans == 4 ? -1 : ans);
	return 0;
}