#include <iostream>
using namespace std;

int n, m, bl[100000], ans = 1e9 + 1, sum;

bool chk(int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> bl[i];
		sum += bl[i];
	}
	int left = 1, right = sum, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (chk(mid)) {
			ans = ans > mid ? mid : ans;
			right = mid - 1; 
		}
		else left = mid + 1;
	}
	cout << ans;
	return 0;
}

bool chk(int mid) {
	int cnt = 1, s = 0;
	for (int i = 0; i < n; ++i) {
		if (bl[i] > mid) return 0;
		s += bl[i];
		if (s > mid) {
			s = bl[i];
			cnt++;
		}
	}
	return m >= cnt;
}