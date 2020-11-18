#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0;i < n;++i) cin >> a[i];
	sort(a, a + n);
	int cnt = 0, idx = 0, mx = 0;
	for (int i = 0;i < n - 1;++i) {
		if (a[i] == a[i + 1]) {
			if (mx < ++cnt) mx = cnt, idx = i;
		}
		else cnt = 0;
	}
	cout << a[idx];
	return 0;
}