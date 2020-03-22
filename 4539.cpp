#include <iostream>
#include <cmath>
using namespace std;

int n, x, cnt, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> x;
		for (cnt = 0; pow(10, cnt) < x; ++cnt);
		ans = x;
		for (int i = 1; i < cnt; ++i) {
			double d = (double)x / pow(10, i);
			ans = (int)(d + 0.5);
			ans *= pow(10, i);
			x = ans;
		}
		cout << ans << '\n';
	}
	return 0;
}