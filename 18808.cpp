#include <iostream>
using namespace std;

int n, m, k, r, c, map[40][40], st[10][10], ans;

bool cmp(int y, int x) {
	// 이미 스티커가 붙어 있을 경우 return false
	for (int i = 0;i < r;++i) for (int j = 0;j < c;++j) if (st[i][j] & map[y + i][x + j]) return 0;
	// 겹치는 부분이 없을 경우 스티커를 붙임, return true
	for (int i = 0;i < r;++i) for (int j = 0;j < c;++j) if (st[i][j]) map[y + i][x + j] = 1;
	return 1;
}

bool chk() {
	// n-r, m-c 로 스티커 범위에 맞춰서 검사
	for (int i = 0;i <= n - r;++i) for (int j = 0;j <= m - c;++j) if (cmp(i, j)) return 1;
	return 0;
}

void rotate() {
	int tmp[10][10];
	for (int i = 0;i < r;++i) for (int j = 0;j < c;++j) tmp[i][j] = st[i][j];
	for (int i = 0;i < c;++i) for (int j = 0;j < r;++j) st[i][j] = tmp[r - j - 1][i];
	int t = r; r = c; c = t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0;i < r;++i) for (int j = 0;j < c;++j) cin >> st[i][j];
		// 0, 90, 180, 270도 ==> 4번 확인 해야 함
		for (int i = 0;i < 4;++i) {
			if (chk()) break;
			rotate();
		}
	}
	for (int i = 0;i < n;++i) for (int j = 0;j < m;++j) if (map[i][j]) ans++;
	cout << ans;
	return 0;
}
