#include <iostream>
using namespace std;
typedef long long int llt;

llt x, y;
int z;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> x >> y;
	z = (y * 100) / x;
	if (z >= 99) {
		cout << -1;
		return 0;
	}
	int left = 0, right = 1e9, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		llt tmp = ((y + mid) * 100) / (x + mid);
		if (z < tmp) right = mid - 1;
		else left = mid + 1;
	}
	cout << left;
	return 0;
}