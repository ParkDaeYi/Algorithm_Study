#include <iostream>
using namespace std;

int n, x, y, ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> x >> y;
	if (x > y) swap(x, y);
	while (x != y) {
		x = x % 2 ? x / 2 + 1 : x / 2;
		y = y % 2 ? y / 2 + 1 : y / 2;
		ans++;
	}
	cout << ans;
	return 0;
}