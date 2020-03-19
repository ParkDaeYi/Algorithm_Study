#include <stdio.h>
#pragma warning(disable:4996)

int n, m, r, c, row[1000], col[1000];

int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
	scanf("%d %d\n", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0, x; j < m; ++j) {
			scanf("%1d", &x);
			row[i] += x;
			col[j] += x;
		}
	}
	for (int i = 0; i < n; ++i) r += row[i] % 2;
	for (int i = 0; i < m; ++i) c += col[i] % 2;
	if (r % 2 == 0 && c % 2 == 0) printf("%d", min(r + c, n - r + m - c));
	else if (r % 2 && c % 2) printf("%d", min(r + m - c, c + n - r));
	else printf("-1");
	return 0;
}