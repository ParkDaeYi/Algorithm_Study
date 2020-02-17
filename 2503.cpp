#include <iostream>
#include <string>
using namespace std;

bool flag[1000];
int n, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 123; i <= 987; ++i) {
		string tmp = to_string(i);
		if (tmp[0] == tmp[1] || tmp[0] == tmp[2] || tmp[1] == tmp[2]) flag[i] = 1;
		if (tmp[0] == '0' || tmp[1] == '0' || tmp[2] == '0') flag[i] = 1;
	}
	cin >> n;
	for (int t = 0; t < n; ++t) {
		int num, strike, ball;
		cin >> num >> strike >> ball;
		for (int i = 123; i <= 987; ++i) {
			if (!flag[i]) {
				int s_cnt = 0, b_cnt = 0;
				string str1 = to_string(num), str2 = to_string(i);
				for (int a = 0; a < 3; ++a) {
					for (int b = 0; b < 3; ++b) {
						if (a == b && str1[a] == str2[b]) ++s_cnt;
						else if (a != b && str1[a] == str2[b]) ++b_cnt;
					}
				}
				if (strike != s_cnt || ball != b_cnt) flag[i] = 1;
			}
		}
	}
	for (int i = 123; i <= 987; ++i) if (!flag[i]) ++ans;
	cout << ans;
	return 0;
}