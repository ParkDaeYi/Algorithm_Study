#include <iostream>
#include <stack>
#include <string>
using namespace std;

int n, cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		string str;
		stack<char> s;
		cin >> str;
		for (int i = 0; i < str.length(); ++i) {
			if (s.empty()) s.push(str[i]);
			else if (s.top() == str[i]) s.pop();
			else s.push(str[i]);
		}
		if (s.empty()) ++cnt;
	}
	cout << cnt;
	return 0;
}
