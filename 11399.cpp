#include <iostream>
#include <algorithm>
using namespace std;

int n, p[1001], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;++i) cin >> p[i];
	sort(p, p + n);
	for (int i = 0;i < n;++i) for (int j = 0;j <= i;++j) ans += p[j];
	cout << ans;
	return 0;
}