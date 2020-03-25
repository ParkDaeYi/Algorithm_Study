#include <iostream>
#define MOD 1000000
using namespace std;
typedef long long int llt;

llt n, f[1500015];

void fibonacci() {
	f[0] = 0; f[1] = 1;
	for (int i = 0;i < n % 1500000;++i) f[i + 2] = (f[i + 1] + f[i]) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	fibonacci();
	cout << f[n % 1500000];
	return 0;
}

/*
 피사노 주기 특징

- m > 2 일 경우 fisano(m) 은 짝수
- fisano(m) <= m^2 - 1
- fisano(2^n) = 3 * 2^(n - 1)
- fisano(5^n) = 4 * 5^n
- fisano(2 * 5^n) = 6 * n
- n > 2 , fisano(10^n) = 15 * 10^(n - 1)
*/