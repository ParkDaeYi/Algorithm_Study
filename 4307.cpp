#include <iostream>
#include <algorithm>
using namespace std;

int T, l, n, x;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		int mn = 0, mx = 0;
		cin >> l >> n;
		while(n--) {
			cin >> x;
			mx = max(mx, max(x, l - x));
			mn = max(mn, min(x, l - x));
		}
		cout << mn << ' ' << mx << '\n';
	}
	return 0;
}