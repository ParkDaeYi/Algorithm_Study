#include <iostream>
using namespace std;

int n, arr[200], lis[200];

int lower_bd(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	int arr_idx = 0, lis_idx = 0;
	lis[0] = arr[arr_idx++];
	while (arr_idx < n) {
		if (lis[lis_idx] < arr[arr_idx]) lis[++lis_idx] = arr[arr_idx];
		else {
			int itr = lower_bd(0, lis_idx, arr[arr_idx]);
			lis[itr] = arr[arr_idx];
		}
		arr_idx++;
	}
	cout << n - lis_idx - 1;
	return 0;
}

int lower_bd(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) >> 1;
		if (lis[mid] < target) left = mid + 1;
		else right = mid;
	}
	return right;
}