#include <iostream>
#include <algorithm>
#define INF 1e9+1
using namespace std;
typedef pair<int, int> pii;

int n;
pii arr[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n);
	int ans = 0, left = arr[0].first, right = arr[0].second;
	for (int i = 1; i < n; ++i) {
		if (right < arr[i].first) {
			ans += right - left;
			left = arr[i].first;
			right = arr[i].second;
		}
		else right = max(right, arr[i].second);
	}
	ans += right - left;
	cout << ans << '\n';
	return 0;
}