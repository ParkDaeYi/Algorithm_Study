#include <iostream>
using namespace std;
typedef long long int llt;

llt N, A, ans;

llt gcd(llt a, llt b) { return b ? gcd(b, a % b) : a; }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> A;
	cout << N - A << ' ';	// 덧셈의 역원의 경우는 A = B (MOD N)에서 N - A를 하면 된다 ==> (A + B) MOD N = 0
	// 곱셈의 역원은 Ax = B (MOD N)와 같은 식을 사용한다
	// 이 식은 x = B * A^-1 (MOD N) 으로 나타낼 수 있다.
	// 여기서 우리는 A^-1을 구해야 하는데
	// 확장 유클리드 호제법을 통해 Ns + At = 1 식을 이용한다.
	if (gcd(N, A) != 1) cout << -1;
	else {
		llt q = 0, tmp = 0, r1 = N, r2 = A, t1 = 0, t2 = 1;
		while (r2) {
			q = r1 / r2;
			tmp = r1;
			r1 = r2;
			r2 = tmp - r1 * q;
			tmp = t1;
			t1 = t2;
			t2 = tmp - t1 * q;
		}
		while (t1 < 0) t1 += N;
		cout << t1;
	}
	return 0;
}