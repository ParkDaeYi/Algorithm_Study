#include <iostream>
using namespace std;

int n, a = 300, b = 60, c = 10;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	if (n % 10 != 0) cout << -1;
	else {
		cout << n / a << ' ';
		n %= a;
		cout << n / b << ' ';
		n %= b;
		cout << n / c;
	}
	return 0;
}