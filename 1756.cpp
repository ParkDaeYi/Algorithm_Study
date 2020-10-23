#include <iostream>
#include <algorithm>
using namespace std;

int d, n, arr[300001], piz;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> d >> n;
	arr[0] = 1e9;
	for (int i = 1;i <= d;++i) {
		cin >> arr[i];
		arr[i] = min(arr[i], arr[i - 1]);
	}
	while (n--) {
		cin >> piz;
		while (d > 0 && arr[d] < piz) --d;
		--d;
	}
	cout << (d < 0 ? 0 : d + 1);
	return 0;
}