#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int cnt = 0, sz = str.length();
		for (int i = 0; i < sz && cnt >= 0; ++i) str[i] == '(' ? cnt++ : cnt--;
		cnt ? cout << "NO\n" : cout << "YES\n";
	}
	return 0;
}