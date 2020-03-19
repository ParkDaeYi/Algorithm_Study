#include <stdio.h>
#include <algorithm>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int n, ans, arr[100001], rmd;

int main() {

	scanf("%d\n", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
		ans += arr[i];
	}
	sort(arr, arr + n, greater<int>());
	rmd = n % 3;
	for (int i = 2; i < n - rmd; i += 3) ans -= arr[i];
	printf("%d", ans);
	return 0;
}