#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	cin >> str;
	vector<string> ans;
	for (int i = 0;i < str.length();++i) ans.emplace_back(str.substr(i));
	sort(ans.begin(), ans.end());
	for (string s : ans) cout << s << '\n';
	return 0;
}