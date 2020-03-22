#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int llt;

int n, w, arr[15];
llt ans, v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> ans;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 0; i < n - 1;) {
		while (arr[i] >= arr[i + 1] && i < n - 1) ++i;
		v = ans / arr[i];
		ans -= v * arr[i];
		while (arr[i] <= arr[i + 1] && i < n - 1) ++i;
		ans += v * arr[i];
	}
	cout << ans;
	return 0;
}