#include <iostream>
#include <algorithm>
using namespace std;

int n, l, arr[1000], cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	int s = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[i] - s + 1 > l) {
			s = arr[i];
			cnt++;
		}
	}
	cout << cnt + 1;
	return 0;
}