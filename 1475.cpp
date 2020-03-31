#include <iostream>
#include <string>
using namespace std;

int num[10], ans;
string str;

int max_int(int a, int b) { return a > b ? a : b; }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str;
	for (int i = 0;i < str.size();++i) {
		if (str[i] == '9' || str[i] == '6') ans = num[6] > num[9] ? max_int(ans, ++num[9]) : max_int(ans, ++num[6]);	
		else ans = max_int(ans, ++num[str[i] - '0']);
	}	
	cout << ans;
	return 0;
}