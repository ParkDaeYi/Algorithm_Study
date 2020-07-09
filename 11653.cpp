#include <iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 2;i * i < n + 1;++i) {
		while (n % i == 0) {
			cout << i << '\n';
			n /= i;
		}
	}
	if (n > 1) cout << n;	// 현재 n이 소수일 경우
	return 0;
}