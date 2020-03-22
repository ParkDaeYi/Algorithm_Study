#include <iostream>
using namespace std;

int n, ans[40000], arr[40000];

int lower_bd(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	int arr_idx = 1, ans_idx = 0;
	ans[0] = arr[0];
	while (arr_idx < n) {
		if (ans[ans_idx] < arr[arr_idx]) ans[++ans_idx] = arr[arr_idx];
		else {
			int itr = lower_bd(0, ans_idx, arr[arr_idx]);
			ans[itr] = arr[arr_idx];
		}
		++arr_idx;
	}
	cout << ans_idx + 1;
	return 0;
}

int lower_bd(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (ans[mid] < target) left = mid + 1;
		else right = mid;
	}
	return right;
}