#include <iostream>
using namespace std;
typedef long long int llt;

llt _pow(llt, llt, llt);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	llt a, b, c;
	cin >> a >> b >> c;
	cout << _pow(a, b, c);
	return 0;
}

llt _pow(llt a, llt b, llt c) {
	if (b == 0) return 1;
	llt ans = _pow(a, b / 2, c);
	ans = ans * ans % c;
	if (!(b % 2)) return ans;
	else return ans * a % c;
}