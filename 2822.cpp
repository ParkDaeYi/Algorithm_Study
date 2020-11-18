#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
typedef pair<int, int> pii;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	pii a[8];
	for (int i = 0;i < 8;++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + 8, greater<pii>());
	int sum = 0, idx[5];
	for (int i = 0;i < 5;++i) {
		sum += a[i].first;
		idx[i] = a[i].second;
	}
	cout << sum << '\n';
	sort(idx, idx + 5);
	for (int i = 0;i < 5;++i) cout << idx[i] + 1 << ' ';
	return 0;
}