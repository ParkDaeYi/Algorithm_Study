#include <iostream>
using namespace std;
typedef long long int llt;

llt x, y;
int z;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> x >> y;
	z = (y * 100) / x;
	if (z >= 99) cout << -1;
	else {
		int left = 0, right = x;
		while (left <= right) {
			int mid = (left + right) >> 1;
			llt ret = ((y + mid) * 100) / (x + mid);
			if (z < ret) right = mid - 1;
			else left = mid + 1;	// 마지막으로 늘어난 left 값이 최소 판 수가 된다
		}
		cout << left;	// 몇 판 더해야 z가 변하는지를 물어봤기 때문에 최소 판 수가 답이 된다
	}
	return 0;
}