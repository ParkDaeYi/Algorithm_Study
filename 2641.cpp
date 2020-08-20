#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, m, cnt;
string ans[100], str1, str2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	char c;
	for (int i = 0;i < n;++i) {
		cin >> c;
		str1 += c;	// 정방향
		str2 += (c + 1) % 4 + 1 + '0';	// 역방향
	}
	// #include <algorithm> 있어야 reverse 사용 가능
	// 역방향은 reverse를 해줘야 정방향과 같은 도형이 됨
	reverse(str2.begin(), str2.end());
	cin >> m;
	while (m--) {
		string q = "";
		for (int i = 0;i < n;++i) {
			cin >> c;
			q += c;
		}
		string tmp = q;
		for (int i = 0;i < n;++i) {
			// 정방향, 역방향 둘중 하나와 같을 경우
			if (tmp == str1 || tmp == str2) {
				ans[cnt++] = q;
				break;
			}
			tmp = tmp.substr(1, n) + tmp[0];
		}
	}
	cout << cnt << '\n';
	for (int i = 0;i < cnt;++i) {
		for (char s : ans[i]) cout << s << ' ';
		cout << '\n';
	}
	return 0;
}