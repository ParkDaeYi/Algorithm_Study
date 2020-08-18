#include <iostream>
using namespace std;

int n, cycle, a, b;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int tmp = n;
	do {
		a = tmp % 10;
		b = (tmp / 10 + tmp % 10) % 10;
		tmp = a * 10 + b;
		cycle++;
	} while (tmp != n);
	cout << cycle;
	return 0;
}