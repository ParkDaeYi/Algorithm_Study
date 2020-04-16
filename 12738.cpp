#include <iostream>
#define MAX_N 1000001
using namespace std;

int n, arr[MAX_N], ans[MAX_N];

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
	while (h < n) {
		if (ans[l] < arr[h]) ans[++l] = arr[h];
		else {
			int p = lower_bd(0, l, arr[h]);
			ans[p] = arr[h];
		}
		h++;
	}
	cout << l + 1;
	return 0;
}