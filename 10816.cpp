#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[500000], ans;

int lower_bd(int, int, int);
int upper_bd(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int num;
		cin >> num;
		int low = lower_bd(0, n, num), upp = upper_bd(0, n, num);
		cout << upp - low << ' ';
	}
	return 0;
}

int lower_bd(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] < target) left = mid + 1;
		else right = mid;
	}
	return right;
}

int upper_bd(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] <= target) left = mid + 1;
		else right = mid;
	}
	return right;
}