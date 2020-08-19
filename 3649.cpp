#include <iostream>
#include <algorithm>
using namespace std;

int x, n, arr[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// "입력은 여러 개의 테스트 케이스로 이루어져 있다."
	// 라고 적혀있음;;
	while (cin >> x) {
		cin >> n;
		x *= 10000000;
		for (int i = 0;i < n;++i) cin >> arr[i];
		sort(arr, arr + n);
		int lo = 0, hi = n - 1, sum = 0;
		while (lo < hi) {
			sum = arr[lo] + arr[hi];
			if (sum == x) break;
			else if (sum < x) lo++;
			else hi--;
		}
		if (sum == x) cout << "yes " << arr[lo] << ' ' << arr[hi] << '\n';
		else cout << "danger\n";
	}
	return 0;
}