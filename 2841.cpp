#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> pii;

stack<int> s[7];
int n, p, cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;	
		while (1) {
			if (s[a].empty()) {
				s[a].push(b);
				++cnt;
				break;
			}
			if (b == s[a].top()) break;
			else if (b < s[a].top()) {
				s[a].pop();
				++cnt;
			}
			else {
				s[a].push(b);
				++cnt;
			}
		}
	}
	cout << cnt;
	return 0;
}