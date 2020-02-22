#include <iostream>
using namespace std;

int money[6] = { 500,100,50,10,5,1 }, n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int tmp = 1000 - n, cnt = 0;
	for (int i = 0; i < 6; ++i) {
		cnt += tmp / money[i];
		tmp %= money[i];
	}
	cout << cnt;
	return 0;
}