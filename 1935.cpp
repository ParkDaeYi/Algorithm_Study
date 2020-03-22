#include <iostream>
#include <stack>
#include <string>
using namespace std;

int alph[26], n;
stack<double> ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string str;
	cin >> str;
	for (int i = 0; i < n; ++i) cin >> alph[i];
	for (int i = 0; i < str.length(); ++i) {
		if (65 <= str[i] && str[i] <= 90) {
			ans.push(alph[str[i] - 'A']);
		}
		else {
			char symbol = str[i];
			double op1 = ans.top(); ans.pop();
			double op2 = ans.top(); ans.pop();
			double ret;
			switch (symbol) {
			case '*': ret = op2 * op1; break;
			case '/': ret = op2 / op1; break;
			case '+': ret = op2 + op1; break;
			case '-': ret = op2 - op1; break;
			}
			ans.push(ret);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << ans.top();
	return 0;
}
