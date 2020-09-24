#include <iostream>
#include <vector>
#include <string>
#pragma warning(disable:4996)
using namespace std;

string str;
vector<char> op;
vector<int> num;

int main() {
	//freopen("inp.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str;
	string tmp = "";
	int ans = 0;
	bool m = 0;
	str += '+';
	for (int i = 0;i < str.length();++i) {
		if (str[i] == '-' || str[i] == '+') {
			if (!m) ans += stoi(tmp);
			else ans -= stoi(tmp);
			if (str[i] == '-') m = 1;
			tmp = "";
		}
		else tmp += str[i];
	}
	cout << ans;
	return 0;
}