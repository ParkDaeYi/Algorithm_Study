#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	//freopen("p10137.inp", "r", stdin);
	//freopen("p10137.out", "w", stdout);

	int n;
	while (scanf("%d", &n)) {
		if (!n) break;
		double tot = 0, pls = 0, mis = 0, tmp, arr[1010];
		for (int i = 0; i < n; ++i) {
			scanf("%lf", arr + i);
			tot += arr[i];
		}
		tot /= n;
		for (int i = 0; i < n; ++i) {
			int dif = ((arr[i] - tot) * 100.0);
			if (dif < 0) mis += dif;
			else pls += dif;
		}
		printf("$%.2lf\n", (-mis > pls ? -mis : pls) / 100);
	}
	return 0;
}