#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;

int n, d, k, c, arr[35000], cnt[3001], ans, cur;

int main() {

	scanf("%d %d %d %d\n", &n, &d, &k, &c);
	for (int i = 0; i < n; ++i) scanf("%d", arr + i);
	for (int i = 0; i < k - 1; ++i) arr[n + i] = arr[i];
	cnt[c]++;
	cur++;
	for (int i = 0; i < k - 1; ++i) if (!cnt[arr[i]]++) cur++;
	for (int i = 0; i < n; ++i) {
		if (!cnt[arr[i + k - 1]]++) cur++;
		ans = ans > cur ? ans : cur;
		if (!(--cnt[arr[i]])) cur--;
	}
	printf("%d", ans);
	return 0;
}