#include <iostream>
using namespace std;

char c;
int sum, num[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	while (cin >> c) {
		num[c - '0'] += 1;
		sum += c - '0';
	}
	if (!num[0] || sum % 3 != 0) cout << -1;	// 30의 배수 이므로 0은 꼭 포함되어야 하며, 3의 배수 특성을 이용
	else {
		for (int i = 9;i >= 0;--i) {
			for (int j = 0;j < num[i];++j) cout << i;
		}
	}
	return 0;
}