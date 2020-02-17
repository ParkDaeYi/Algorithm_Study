#include <iostream>
using namespace std;

int dp[45], n, num;

bool backt(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i < 45; ++i) dp[i] = dp[i - 1] + i;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (backt(0, 0)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}

bool backt(int cnt,int sum) {
	if (cnt > 3) return 0;
	if (cnt == 3 && sum == num) return 1;
	if (cnt == 3 && sum != num) return 0;
	for (int i = 1; i < 45; ++i) {
		if (sum + dp[i] > num) return 0;
		if (backt(cnt + 1, sum + dp[i])) return 1;
	}
}