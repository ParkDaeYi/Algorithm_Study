#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[100000];

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
		int left = 0, right = n, mid;
		bool flag = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			if (arr[mid] == num) {
				flag = 1; break;
			}
			else if (arr[mid] < num) left = mid + 1;
			else right = mid - 1;
		}
		flag ? cout << "1\n" : cout << "0\n";
	}
	return 0;
}