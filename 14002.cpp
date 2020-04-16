#include <iostream>
#include <stack>
#define MAX_N 1001
using namespace std;
typedef pair<int, int> pii;

int n, arr[MAX_N], ans[MAX_N];
pii lis[MAX_N];

int lower_bd(int l, int r, int t) {
	int mid;
	while (l < r) {
		mid = (l + r) >> 1;
		if (ans[mid] < t) l = mid + 1;
		else r = mid;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	int l = 0, h = 1;
	ans[0] = arr[0];
	lis[0] = pii(0, arr[0]);
	while (h < n) {
		if (ans[l] < arr[h]) {
			ans[++l] = arr[h];
			lis[h] = pii(l, arr[h]);
		}
		else {
			int p = lower_bd(0, l, arr[h]);
			ans[p] = arr[h];
			lis[h] = pii(p, arr[h]);
		}
		h++;
	}
	cout << l + 1 << '\n';
	int idx = l;
	stack<int> s;
	for (int i = n - 1; i >= 0; --i) {
		if (lis[i].first == idx) {
			s.push(lis[i].second);
			--idx;
		}
	}
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	return 0;
}