// 완전(교란) 순열
// 점화식
// 1) D(n) = n * D(n - 1) + (-1)^n
// 2) D(n) = (n - 1)(D(n - 1) + D(n - 2))
#include <iostream>
#define MOD 1000000000
using namespace std;
typedef long long int llt;

int n;
llt a, b = 1, c;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (llt i = 3; i <= n; ++i) {
		c = (i - 1) * (a + b) % MOD;
		a = b, b = c;
	}
	if (n == 1) cout << 0;
	else if (n == 2) cout << 1;
	else cout << c;
	return 0;
}