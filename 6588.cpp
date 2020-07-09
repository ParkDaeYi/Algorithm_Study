#include <iostream>
#define MAX_N 1000000
using namespace std;

int n;
bool prime[MAX_N + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// 에라토스테네스의 체
	// 인덱스 번호로 소수 판별
	for (int i = 2;i * i < MAX_N + 1;++i) {
		if (prime[i]) continue;
		for (int j = i * i;j < MAX_N + 1;j += i) prime[j] = 1;
		
	}

	while (1) {
		cin >> n;
		if (!n) break;
		bool flag = 0;
		for (int i = 3;i < n - 2;i += 2) {
			if (!prime[i] && !prime[n - i]) {
				// i 와 n - i 가 서로 소수일 경우
				cout << n << " = " << i << " + " << n - i << '\n';
				flag = 1; break;
			}
		}
		if (!flag) cout << "Goldbach's conjecture is wrong.\n";
	}

	return 0;
}