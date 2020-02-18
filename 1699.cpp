#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;

int n, dp[MAX];
vector<int> vec;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i * i <= n; ++i) vec.push_back(i * i);
	fill(dp, dp + n + 1, MAX);
	dp[0] = 0;
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = vec[i]; j <= n; ++j) dp[j] = min(dp[j], dp[j - vec[i]] + 1);	
	}
	cout << dp[n];
	return 0;
}