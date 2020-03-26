#include <iostream>
#include <string>
using namespace std;
typedef long long int llt;

string ans;
llt dp[100], sum[100], n;
int idx, sz;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	dp[1] = dp[2] = sum[1] = 1;
	sum[2] = 2;
	if (n != 1 && n != 2) {
		for (int i = 3;;++i) {
			dp[i] = dp[i - 1] + dp[i - 2];
			sum[i] = sum[i - 1] + dp[i];
			if (sum[i] >= n) {
				sz = idx = i;
				break;
			}
		}
		while (1) {
			ans += '1';
			ans += '0';
			n -= (sum[idx - 1] + 1);
			idx -= 2;
			for (int i = idx - 1;i > 0;--i) {
				if (sum[i] < n) {
					idx = i + 1;
					break;
				}
				ans += '0';
			}
			if (n == 1) {
				if (ans.length() + 2 == sz) ans += '0';
				ans += '1';
				break;
			}
			if (n == 2) {
				ans += '1';
				ans += '0';
				break;
			}
			if (n == 0) {
				if (ans.length() + 2 == sz) ans += '0';
				ans += '0';
				break;
			}
		}
	}
	else if (n == 1) ans += '1';
	else if (n == 2) {
		ans += '1';
		ans += '0';
	}
	cout << ans;
	return 0;
}