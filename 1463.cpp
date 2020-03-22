#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001], n;

int one_maker(int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	cout << one_maker(n);
	return 0;
}

int one_maker(int n) {
	if (n == 1) return 0;
	if (dp[n]) return dp[n];
	int ret = one_maker(n - 1) + 1;
	if (!(n % 3)) ret = min(ret, one_maker(n / 3) + 1);
	if (!(n % 2)) ret = min(ret, one_maker(n / 2) + 1);
	return dp[n] = ret;
}