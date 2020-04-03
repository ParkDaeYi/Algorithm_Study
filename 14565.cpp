#include <iostream>
using namespace std;
typedef long long int llt;

llt a, b, ans;

llt gcd(llt a, llt b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b;
	cout << a - b << ' ';
	if (gcd(a, b) != 1) cout << -1;
	else {
		llt q = 0, tmp = 0, r1 = a, r2 = b, t1 = 0, t2 = 1;
		while (r2) {
			q = r1 / r2;
			tmp = r1;
			r1 = r2;
			r2 = tmp - r2 * q;
			tmp = t1;
			t1 = t2;
			t2 = tmp - t2 * q;
		}
		while (t1 < 0) t1 += a;
		cout << t1;
	}
	return 0;
}