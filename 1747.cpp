#include <iostream>
#define M 2000000
using namespace std;

// prime[1] = 1 로 체크 안해주면 100퍼에서 틀림
bool prime[M] = { 1,1, };

bool chk(int a[], int l, int r) {
	for (;l <= r;l++, r--) if (a[l] != a[r]) return 0;
	return 1;
}

bool arr(int p) {
	int sz = -1, a[7];
	while (p) {
		a[++sz] = p % 10;
		p /= 10;
	}
	return chk(a, 0, sz);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 2;i * i < M;++i) 
		if (!prime[i]) for (int j = i * i;j < M;j += i) prime[j] = 1;
	
	int n;
	cin >> n;
	for (int i = n;i < M;++i) {
		if (prime[i]) continue;
		if (arr(i)) {
			cout << i;
			break;
		}
	}
	return 0;
}