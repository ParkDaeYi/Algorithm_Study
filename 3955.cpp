#include <iostream>
#define MAX 1e9
using namespace std;
typedef long long int llt;

int t;
llt k, c;

inline llt gcd(llt a, llt b) { return b == 0 ? a : gcd(b, a % b); }

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
		/*
		k * s + c * t = gcd(k,c)

		q[i] : r[i-1] / r[i] (i >= 1)
		=> q = r1 / r2
		
		r[i] : r[i-2] - r[i-1] * q[i-1] (i >= 2)
		=> r1 = k , r2 = c
		=> tmp = r1, r1 = r2, r2 = tmp - r2 * q
		
		s[i] : s[i-2] - s[i-1] * q[i-1]
		=> s1 = 1, s2 = 0
		=> tmp = s1, s1 = s2, s2 = tmp - s2 * q

		t[i] : t[i-2] - t[i-1] * q[i-1]
		=> t1 = 0, t2 = 1
		=> tmp = t1, t1 = t2, t2 = tmp - t2 * q
		*/
		llt q = 0, tmp = 0, r1 = k, r2 = c, t1 = 0, t2 = 1;
		while (r2) {
			q = r1 / r2;
			tmp = r1;
			r1 = r2;
			r2 = tmp - r2 * q;
			tmp = t1;
			t1 = t2;
			t2 = tmp - t2 * q;
		}
		while (t1 < 0) t1 += k;
		if (t1 > MAX) cout << "IMPOSSIBLE\n";
		else cout << t1 << '\n';
	}
	return 0;
}