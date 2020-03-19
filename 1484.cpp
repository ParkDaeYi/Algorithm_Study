#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)
typedef long long int llt;

int g;

int main() {

	scanf("%d", &g);
	bool flag = 0;
	llt c = (int)sqrt(g) + 1, r = 1;
	while (1) {
		if (c * c - r * r == g) {
			flag = 1;
			printf("%d\n", c);
		}
		if (c - r == 1 && c * c - r * r > g) break;
		if (c * c - r * r > g) r++;
		else c++;
	}
	if (!flag) printf("-1");
	return 0;
}