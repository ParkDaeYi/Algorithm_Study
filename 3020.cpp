#include <iostream>
#include <algorithm>
using namespace std;

int n, h, bot[100000], top[100000], ans = 1e6 + 1, cnt;

int lower_bd(int[], int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> h;
	int i, j;
	for (i = 0, j = 0; i + j < n;) {
		!((i + j) % 2) ? cin >> bot[i++] : cin >> top[j++];
	}
	sort(bot, bot + i);
	sort(top, top + j);
	for (int high = 1; high <= h; ++high) {
		int b = i - lower_bd(bot, 0, i, high);
		int t = j - lower_bd(top, 0, j, h - high + 1);
		if (ans > b + t) {
			ans = b + t;
			cnt = 1;
		}
		else if (ans == b + t) ++cnt;
	}
	cout << ans << ' ' << cnt;
	return 0;
}

int lower_bd(int arr[],int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] < target) left = mid + 1;
		else right = mid;
	}
	return right;
}