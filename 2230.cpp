#include <stdio.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int n, m, arr[100001];

int main() {

	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", arr + i);
	sort(arr, arr + n);
	int l = 0, h = 0, ans = arr[n - 1] - arr[0];
	while (l <= h && h < n) {
		if (arr[h] - arr[l] < m) h++;
		else {
			ans = min(ans, arr[h] - arr[l++]);
			if (l > h && l < n) h = l;		
		}
	}
	printf("%d", ans);
	return 0;
}