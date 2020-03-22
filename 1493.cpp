#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int llt;

llt a[20], l, w, h, n, sz, cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> l >> w >> h >> n;
	for (int i = 0, x, y; i < n; ++i) cin >> x >> y, a[x] = y;
	for (int i = 19; i >= 0; --i) {
		sz <<= 3;
		llt tmp = min((llt)a[i], (llt)(l >> i) * (w >> i) * (h >> i) - sz);
		sz += tmp; cnt += tmp;
	}
	sz == l * w * h ? cout << cnt : cout << -1;
	return 0;
}