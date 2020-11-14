#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str, pt;
	getline(cin, str);
	getline(cin, pt);
	int l = 0, cnt = 0, n = str.length(), m = pt.length();
	while (l <= n - m) {
		if (str[l] == pt[0]) {
			bool f = 0;
			for (int i = 0;i < m;++i) {
				if (str[l + i] != pt[i]) { f = 1; break; }
			}
			if (!f) {
				l += m - 1; ++cnt;
			}
		}
		++l;
	}
	cout << cnt;
	return 0;
}