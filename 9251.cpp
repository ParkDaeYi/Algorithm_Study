#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str1 >> str2;
	int sz1 = str1.length(), sz2 = str2.length();
	for (int i = 0; i < sz1; ++i) {
		for (int j = 0; j < sz2; ++j) {
			if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = dp[i + 1][j] > dp[i][j + 1] ? dp[i + 1][j] : dp[i][j + 1];
		}
	}
	cout << dp[sz1][sz2];
	return 0;
}