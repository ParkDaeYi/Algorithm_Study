#include <iostream>
#define MAX_N 1000001
#define MOD 1000000007
using namespace std;
typedef long long int llt;

int n, m;
llt fac[MAX_N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	fac[0] = fac[1] = 1;
	for (int i = 2; i < n + 1; ++i) fac[i] = ((fac[i - 1] % MOD) * i) % MOD;
	llt q = 0, tmp = 0, r1 = MOD, r2 = (fac[n - m] * fac[m]) % MOD, t1 = 0, t2 = 1;
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
	llt ans = (fac[n] * (t1 % MOD));
	cout << ans % MOD;
	return 0;
}