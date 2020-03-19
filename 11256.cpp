#include <stdio.h>
#include <algorithm>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int t, c, n, arr[1001];

int main() {

	scanf("%d\n", &t);
	while (t--) {
		scanf("%d %d\n", &c, &n);
		for (int i = 0, x, y; i < n; ++i) {
			scanf("%d %d", &x, &y);
			arr[i] = x * y;
		}
		sort(arr, arr + n, greater<int>());
		int cnt = 0;
		for (int i = 0; i < n && c > 0; i++) {
			c -= arr[i];
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}