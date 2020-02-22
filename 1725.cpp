//스택
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

//분할정복
//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int n, his[100000];
//
//int divide(int, int);
//
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0); cout.tie(0);
//	cin >> n;
//	for (int i = 0; i < n; ++i) cin >> his[i];
//	cout << divide(0, n - 1);
//	return 0;
//}
//
//int divide(int left, int right) {
//	if (left == right) return his[left];
//	int mid = (left + right) / 2, ret = max(divide(left, mid), divide(mid + 1, right));
//	int start = mid, end = mid + 1, height;
//	height = min(his[start], his[end]);
//	ret = max(ret, height * (end - start + 1));
//	while (left < start || end < right) {
//		if (end < right && (start == left || his[start - 1] < his[end + 1])) height = min(height, his[++end]);
//		else height = min(height, his[--start]);
//		ret = max(ret, height * (end - start + 1));
//	}
//	return ret;
//}
