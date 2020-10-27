#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str;
	while (getline(cin, str)) {
		int n = str.length();
		if (n == 1) break;
		stack<char> st;
		bool flag = 0;
		for (int i = 0;i < n;++i) {
			if (str[i] == '(' || str[i] == '[') st.push(str[i]);
			else if (str[i] == ')' || str[i] == ']') {
				flag = 1;
				if (st.empty()) break; 
				else if (str[i] == ')' && st.top() != '(') break; 
				else if (str[i] == ']' && st.top() != '[') break; 
				flag = 0;
				st.pop();
			}
		}
		if (!st.empty()) flag = 1;
		cout << (flag ? "no" : "yes") << '\n';
	}
	return 0;
}