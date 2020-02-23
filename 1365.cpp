#include <iostream>
using namespace std;

int n, lis[100000];

int lower_bd(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int tmp = n, idx = 0;
	while (tmp--) {
		int num;
		cin >> num;
		if (lis[idx] < num) lis[++idx] = num;
		else {
			int itr = lower_bd(1, idx, num);
			lis[itr] = num;
		}
	}
	cout << n - idx;
	return 0;
}

int lower_bd(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (lis[mid] < target) left = mid + 1;
		else right = mid;
	}
	return right;
}