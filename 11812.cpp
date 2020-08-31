#include <stdio.h>
#pragma warning(disable:4996)
typedef long long ll;

ll n, l, r;
int k, q, cnt;

// (a + k - 2) / k 또는 (a - 2) / k + 1,,,,모르면 못 품;;;
// ==> a 의 부모 찾는 연산
inline ll gp(ll& a) { return (a + k - 2) / k; }
inline ll abs(ll a) { return a < 0 ? -a : a; }

int main() {
	scanf("%lld %d %d\n", &n, &k, &q);
	while (q--) {
		scanf("%lld %lld", &l, &r);
		if (k == 1) {
			printf("%lld\n", abs(l - r));
			continue;
		}
		cnt = 0;
		while (l ^ r) {
			if (l < r) r = gp(r);
			else if (r < l) l = gp(l);
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}