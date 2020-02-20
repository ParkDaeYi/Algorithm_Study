#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n, ans;
pii arr[1000];
stack<pii> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);
	s.push(arr[0]);
	int h = arr[0].second, w, _max;
	for (int i = 1; i < n; ++i) {
		if (h < arr[i].second) {
			_max = 0;
			while (!s.empty()) {
				h = s.top().second;
				w = arr[i].first - s.top().first;
				_max = _max > h * w ? _max : h * w;
				s.pop();
			}
			ans += _max;
			s.push(arr[i]);
			h = arr[i].second;
		}
		else s.push(arr[i]);
	}
	while (!s.empty()) {
		h = s.top().second;
		w = s.top().first;
		int w2 = w;
		s.pop();
		while (!s.empty()) {
			if (h <= s.top().second) {
				w2 = s.top().first;
				break;
			}
			s.pop();
		}
		if (w2 == w) w = 1;
		else w -= w2;
		ans += h * w;
	}
	cout << ans;
	return 0;
}