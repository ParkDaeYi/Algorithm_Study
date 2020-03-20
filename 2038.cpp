#include <stdio.h>
#include <unordered_map>
#pragma warning(disable:4996)
using namespace std;
typedef long long int llt;

int n;
llt sum;
unordered_map<llt, llt> mp;

int main() {
	//freopen("p679.inp", "r", stdin);
	//freopen("p679.out", "w", stdout);

	scanf("%d", &n);
	if (n == 1) {
		printf("1");
		return 0;
	}
	mp[1] = 1;
	sum += 1;
	for (int i = 2; i <= n; ++i) {
		mp[i] = 1 + mp[i - mp[mp[i - 1]]];
		sum += mp[i];
		if (sum >= n) {
			printf("%d", i);
			return 0;
		}
	}
}