#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str1, str2;
int ans, dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str1 >> str2;
	int sz1 = str1.length(), sz2 = str2.length();
	for (int i = 1; i <= sz1; ++i) {
		for (int j = 1; j <= sz2; ++j) {
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;		
			else dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];	
		}
	}
	cout << dp[sz1][sz2] << '\n';
	stack<char> st;
	for (int i = sz1, j = sz2; i > 0 && j > 0;) {
		if (str1[i - 1] == str2[j - 1]) {
			st.push(str1[i - 1]); --i, --j;
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1]) --i;
			else --j;
		}
	}
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
	return 0;
}
