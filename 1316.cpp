#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, cnt = 0; cin >> n;
	for (int i = 0;i < n;++i) {
		string str; cin >> str;
		bool used[26] = { 0, }, flag = 0;
		char chk;
		for (int j = 0;j < str.length();++j) {
			chk = str[j]; 
			if (used[chk - 'a']) { flag = 1; break; }
			used[chk - 'a'] = 1;
			while (j < str.length() && chk == str[j]) ++j;
			--j;
		}
		if (!flag) ++cnt;
	}
	cout << cnt;
	return 0;
}