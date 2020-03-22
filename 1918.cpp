#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str, postfix;
stack<char> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	for (int i = 0; i < str.length(); ++i) {
		if (65 <= str[i] && str[i] <= 90) postfix += str[i];
		else {
			switch (str[i]) {
			case '(': s.push(str[i]); break;
			case '*':
			case '/':
				while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
					postfix += s.top(); s.pop();
				}
				s.push(str[i]); break;
			case '+':
			case '-':
				while (!s.empty() && s.top() != '(') {
					postfix += s.top(); s.pop();
				}
				s.push(str[i]); break;
			case ')':
				while (!s.empty() && s.top() != '(') {
					postfix += s.top(); s.pop();
				}
				s.pop(); break;
			}
		}
	}
	while (!s.empty()) {
		postfix += s.top(); s.pop();
	}
	cout << postfix;
	return 0;
}
