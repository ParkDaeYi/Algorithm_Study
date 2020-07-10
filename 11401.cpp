#include <iostream>
#define MOD 1000000007
#define MAX_N 4000001
using namespace std;
typedef long long int llt;

int n, k;
llt fac[MAX_N], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// nCk % MOD 를 계산해야 한다.
	// 우선 N의 최대 값이 4000000이므로 기존의 방식으로 접근한다면 시간초과가 발생할 것이다.
	// 그렇다면 이항계수의 기존 점화식을 사용하여 접근해 보겠다.
	// nCk = (n!) / (n-k)! * k! 으로 값을 구할 수 있다.
	// n! : A, (n-k)! * k! : B, 1000000007 : MOD 로 지정하여 나타내면
	// (A / B) % MOD 형태가 된다
	// %의 경우 분모는 나눌 수 없으므로
	// (A * B^-1) % MOD 형태로 접근해야 한다.
	// 여기서 B의 역원을 구한 뒤 A와 곱하면 답을 구할 수 있다.
	cin >> n >> k;
	fac[0] = fac[1] = 1;
	for (int i = 2; i <= n; ++i) fac[i] = (fac[i - 1] * i) % MOD;
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
	ans = (fac[n] * t1) % MOD;
	cout << ans;
	return 0;
}