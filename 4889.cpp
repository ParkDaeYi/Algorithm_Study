#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	for (int t = 1;;++t) {
		cin >> str;
		if (str[0] == '-') break;
		int cnt = 0;
		stack<char> st;
		for (int i = 0;i < str.length();++i) {
			if (!st.size() && str[i] == '}') {
				++cnt;
				st.push('{');
			}
			else if (str[i] == '{') st.push('{');
			else st.pop();
		}
		cout << t << ". " << cnt + st.size() / 2 << '\n';
	}
	return 0;
}