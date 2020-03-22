#include <iostream>
using namespace std;

int n, arr[2187][2187], ans[3];

void divide(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> arr[i][j];
	divide(0, 0, n);
	for (int i = 0; i < 3; ++i) cout << ans[i] << '\n';
	return 0;
}

void divide(int y, int x, int sz) {
	if (sz == 1) {
		ans[arr[y][x] + 1]++;
		return;
	}
	int sym = arr[y][x];
	for (int i = y; i < y + sz; ++i) {
		for (int j = x; j < x + sz; ++j) {
			if (sym == arr[i][j]) continue;
			sz /= 3;
			divide(y, x, sz);
			divide(y, x + sz, sz);
			divide(y, x + sz + sz, sz);
			divide(y + sz, x, sz);
			divide(y + sz, x + sz, sz);
			divide(y + sz, x + sz + sz, sz);
			divide(y + sz + sz, x, sz);
			divide(y + sz + sz, x + sz, sz);
			divide(y + sz + sz, x + sz + sz, sz);
			return;
		}
	}
	ans[sym + 1]++;
	return;
}