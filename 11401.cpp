#include <iostream>
#define MOD 1000000007
#define MAX_N 4000001
using namespace std;
typedef long long int llt;

llt fac[MAX_N], n, k, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	fac[0] = fac[1] = 1;
	for (int i = 2;i < n + 1;++i) fac[i] = ((fac[i - 1] % MOD) * i) % MOD;
	/*
	(fac[n-k]! * fac[k]!)^-1 MOD 에 대해 모르니
	(나는) 확장 유클리드 호제법을 통해
	MOD에 대한 (fac[n-k]! * fac[k]!)^-1의 곱셈 역원을 구해줌
	*/
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
	if (t1 < 0)t1 += MOD;
	ans = (fac[n] * (t1 % MOD)) % MOD;
	cout << ans;
	return 0;
}