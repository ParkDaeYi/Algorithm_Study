#include <iostream>
using namespace std;

char map[102][102];
int n, r, c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;++i) cin >> map[i];
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < n - 1;++j) {
			r += map[i][j] == '.' && map[i][j + 1] == '.' && map[i][j + 2] != '.';
			c += map[j][i] == '.' && map[j + 1][i] == '.' && map[j + 2][i] != '.';
		}
	}
	cout << r << ' ' << c;
	return 0;
}