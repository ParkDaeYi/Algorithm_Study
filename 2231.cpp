#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int num, ans = 1;
	cin >> num;
	while (1) {
		int sum = ans, tmp = ans;
		while (tmp) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == num) {
			cout << ans;
			return 0;
		}
		else if (ans == num) {
			cout << 0;
			return 0;
		}
		++ans;
	}
}