#include <iostream>
using namespace std;

int g, l, a, b;

int gcd(int n, int m) { return !m ? n : gcd(m, n % m); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> g >> l;
	l /= g;
	// l /= g 를 안했을 경우에는 i=g;i*i<=l;i+=g 로 하면 됨
 	for (int i = 1;i * i <= l;++i) {
		if (l % i) continue;
		if (gcd(l / i, i) == 1) a = i, b = l / i;
	}
	// g 로 나누고 연산 했으므로 출력 시 다시 곱해줌
	cout << a * g << ' ' << b * g;
	return 0;
}