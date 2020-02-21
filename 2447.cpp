#include <iostream>
using namespace std;

char ans[6561][6561];
int n;

void star(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	fill(&ans[0][0], &ans[n - 1][n], ' ');
	star(n, 0, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) cout << ans[i][j];
		cout << '\n';
	}
	return 0;
}

void star(int num, int y, int x) {
	if (num == 1) {
		ans[y][x] = '*'; return;
	}
	int div = num / 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) continue;
			star(div, y + div * i, x + div * j);
		}
	}
	return;
}