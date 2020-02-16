#include <iostream>
#define MAX 1e9
using namespace std;
typedef long long int llt;

int t;
llt k, c;

inline llt gcd(llt a, llt b) { return b == 0 ? a : gcd(b, a%b); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> k >> c;

		if (c == 1) {
			if (k + 1 > MAX) cout << "IMPOSSIBLE\n";
			else cout << k + 1 << '\n';
			continue;
		}
		if (k == 1) {
			cout << 1 << '\n';
			continue;
		}
		if (gcd(k, c) != 1) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		llt q = 0, tmp = 0, r1 = k, r2 = c, t1 = 0, t2 = 1;
		while (r2) {
			q = r1 / r2;
			tmp = r1;
			r1 = r2;
			r2 = tmp - r2*q;
			tmp = t1;
			t1 = t2;
			t2 = tmp - t2*q;
		}
		while (t1 < 0) t1 += k;
		if (t1 > MAX) cout << "IMPOSSIBLE\n";
		else cout << t1 << '\n';
	}
	return 0;
}

