#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	while (cin >> n) {
		for (int i = 1, ans = 0;i <= n;++i) {
			ans = ans * 10 + 1;
			ans %= n;	// 모듈러의 성질을 통해 계속 나머지를 구해 줌
			if (!ans) {	// ans가 n의 배수이면
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}