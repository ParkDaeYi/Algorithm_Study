#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		string str, ans;
		cin >> str;
		stack<char> s;
		stack<char> tmp;
		for (int i = 0; i < str.length(); ++i) {
			switch (str[i]) {
			case '<':
				if (s.empty()) break;
				else {
					tmp.push(s.top());
					s.pop();
					break;
				}
			case '>':
				if (tmp.empty()) break;
				else {
					s.push(tmp.top());
					tmp.pop();
					break;
				}
			case '-':
				if (!s.empty()) s.pop();
				break;
			default:
				s.push(str[i]); break;
			}
		}
		while (!tmp.empty()) {
			s.push(tmp.top()); tmp.pop();
		}
		while (!s.empty()) {
			ans += s.top(); s.pop();
		}
		for (int i = ans.length() - 1; i >= 0; --i) cout << ans[i];
		cout << '\n';
	}
	return 0;
}