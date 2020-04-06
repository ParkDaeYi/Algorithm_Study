#include <iostream>
#define MAX_N 4000001
#define MOD 1000000007
using namespace std;
typedef long long int llt;

int t, n, k, idx = 2;
llt fac[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	fac[0] = fac[1] = 1;
	while (t--) {
		cin >> n >> k;
		for (; idx < n + 1; ++idx) fac[idx] = (idx * (fac[idx - 1] % MOD)) % MOD;
		llt q = 0, tmp = 0, r1 = MOD, r2 = (fac[n - k] * fac[k]) % MOD, t1 = 0, t2 = 1;
		while (r2) {
			q = r1 / r2;
			tmp = r1;
			r1 = r2;
			r2 = tmp - r2 * q;
			tmp = t1;
			t1 = t2;
			t2 = tmp - t2 * q;
		}
		while (t1 < 0) t1 += MOD;
		llt ans = (fac[n] * (t1 % MOD)) % MOD;
		cout << ans << '\n';
	}
	return 0;
}