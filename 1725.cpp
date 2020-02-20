#include <iostream>
#include <stack>
using namespace std;

int n, arr[100001], ans;
stack<int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i <= n; ++i) {
		while (!s.empty() && arr[s.top()] >= arr[i]) {
			int h = arr[s.top()], w = i;
			s.pop();
			if (!s.empty()) w -= 1 + s.top();
			ans = ans > h * w ? ans : h * w;
		}
		s.push(i);
	}
	cout << ans;
	return 0;
}