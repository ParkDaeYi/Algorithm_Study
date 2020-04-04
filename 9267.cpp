#include <iostream>
using namespace std;
typedef long long int llt;
typedef pair<llt, llt> pll;

llt A, B, S, g;

void swap_llt(llt& a, llt& b) { llt tmp = a; a = b; b = tmp; }
llt abs_llt(llt a) { return a < 0 ? -a : a; }
llt gcd(llt a, llt b) { return b ? gcd(b, a % b) : a; }

pll exgcd(llt a, llt b) {
	if (b == 0) return { 1,0 };
	pll p = exgcd(b, a % b);
	return { p.second,p.first - (a / b) * p.second };
}

bool solve() {
	if (!A && !B) return !S;
	else if (!A) return S % B == 0;
	else if (!B) return S % A == 0;
	g = gcd(A, B);
	if (S % g != 0) return 0;
	pll p = exgcd(A, B);
	llt x = p.first, y = p.second, z = abs_llt(B / g);
	/*
	a += b, b += a 이므로
	x와 y는 양수를 유지해야함
	*/
	x = (x % z) * (S / g % z) % z; //숫자가 너무 크므로 mod 연산을 해줌
	if (x < 0) x += z;
	y = (S - A * x) / B;
	while (y > 0) {
		/*
		두 메모리 셀 중 하나에만 저장되어 있고,
		프로그램의 명령 순서는 정해져 있으므로
		gcd는 1이 되어야함
		*/
		if (gcd(x, y) == 1) return 1;
		x += B / g;
		y -= A / g;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> A >> B >> S;
	if (A > B) swap_llt(A, B);
	cout << (solve() ? "YES" : "NO");
	return 0;
}