#include <iostream>
using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }	// 최대 공약수

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int g1 = a > b ? gcd(a, b) : gcd(b, a), g2 = c > d ? gcd(c, d) : gcd(d, c);	// 각 분수마다 최대 공약수를 구함
	if (g1 != 1) a /= g1, b /= g1;
	if (g2 != 1) c /= g2, d /= g2;
	int lcm = b * d / (b > d ? gcd(b, d) : gcd(d, b));	// 분모들 간의 최소 공배수를 구함
	a *= lcm / b;
	c *= lcm / d;
	int div = (a + c) > lcm ? gcd(a + c, lcm) : gcd(lcm, a + c);	// 구해진 분자와 분모 간의 최대 공약수를 구함
	cout << (a + c) / div << ' ' << lcm / div;
	return 0;
}