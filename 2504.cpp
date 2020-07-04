#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> str;
	if (str.size() % 2) {	// str이 짝수가 아니라면 올바른 괄호가 아님
		cout << 0;
		return 0;
	}

	int tmp = 1, ans = 0;
	stack<char> s;
	for (int i = 0;i < str.size();++i) {
		if (str[i] == '(') {
			tmp *= 2;
			s.push(str[i]);
		}
		else if (str[i] == '[') {
			tmp *= 3;
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {	// () 형식이 아니거나 stack이 비어져 있을 경우
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(') ans += tmp;	
			// (()) 의 경우 (() 에서 값을 연산해줘야 한다. tmp == 4
			// 그렇지 않으면 (())에서 tmp 값(2)이 더해지면서 원하는 값이 안나옴
			tmp /= 2;
			s.pop();
		}
		else {
			if (s.empty() || s.top() != '[') {	// [] 형식이 아니거나 stack이 비어져 있을 경우
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[') ans += tmp;
			tmp /= 3;
			s.pop();
		}
	}
	cout << ans;
	return 0;
}