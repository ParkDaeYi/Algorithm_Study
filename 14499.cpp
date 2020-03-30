#include <iostream>
using namespace std;

int n, m, x, y, k, mp[20][20], dice[7];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mp[i][j];
	while (k--) {
		int q;
		cin >> q;
		q--;
		int nx = x + dx[q], ny = y + dy[q];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		int ndice[7] = { 0, };
		if (q == 0) {
			ndice[3] = dice[1];
			ndice[1] = dice[4];
			ndice[4] = dice[6];
			ndice[6] = dice[3];
			ndice[2] = dice[2];
			ndice[5] = dice[5];
		}
		else if (q == 1) {
			ndice[3] = dice[6];
			ndice[1] = dice[3];
			ndice[4] = dice[1];
			ndice[6] = dice[4];
			ndice[2] = dice[2];
			ndice[5] = dice[5];
		}
		else if (q == 2) {
			ndice[1] = dice[5];
			ndice[5] = dice[6];
			ndice[6] = dice[2];
			ndice[2] = dice[1];
			ndice[3] = dice[3];
			ndice[4] = dice[4];
		}
		else if (q == 3) {
			ndice[1] = dice[2];
			ndice[5] = dice[1];
			ndice[6] = dice[5];
			ndice[2] = dice[6];
			ndice[3] = dice[3];
			ndice[4] = dice[4];
		}
		if (!mp[nx][ny]) mp[nx][ny] = ndice[6];
		else {
			ndice[6] = mp[nx][ny];
			mp[nx][ny] = 0;
		}
		cout << ndice[1] << '\n';
		for (int i = 1; i < 7; ++i) dice[i] = ndice[i];
		x = nx;
		y = ny;
	}
	return 0;
}