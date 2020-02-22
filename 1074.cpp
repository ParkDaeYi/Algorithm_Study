#include <iostream>
using namespace std;

int n, r, c, ans;

void Z(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> r >> c;
	Z(0, 0, 1 << n);
	return 0;
}

void Z(int y, int x, int sz) {
	if (sz == 2) {
		if (y == r && x == c) {
			cout << ans; return;
		}
		ans++;
		if (y == r && x + 1 == c) {
			cout << ans; return;
		}
		ans++;
		if (y + 1 == r && x == c) {
			cout << ans; return;
		}
		ans++;
		if (y + 1 == r && x + 1 == c) {
			cout << ans; return;
		}
		ans++;
		return;
	}
	sz /= 2;
	Z(y, x, sz);
	Z(y, x + sz, sz);
	Z(y + sz, x, sz);
	Z(y + sz, x + sz, sz);
	return;
}