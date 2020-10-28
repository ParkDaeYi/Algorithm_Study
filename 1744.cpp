#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, arr[10000]; cin >> n;
	for (int i = 0;i < n;++i) cin >> arr[i];
	sort(arr, arr + n);
	int l = 0, r = n - 1, sum = 0;
	for (;l < r;l += 2) {
		if (arr[l] < 0 && arr[l + 1] <= 0) sum += arr[l] * arr[l + 1];
		else break;
	}
	for (;r > 0;r -= 2) {
		if (arr[r] > 1 && arr[r - 1] > 1) sum += arr[r] * arr[r - 1];
		else break;
	}
	for (;l <= r;++l) sum += arr[l];
	cout << sum;
	return 0;
}