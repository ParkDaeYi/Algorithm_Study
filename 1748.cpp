#include <iostream>
using namespace std;
typedef long long int llt;

int n, cnt, v, i, j = 1;
llt ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	v = n;
	while (n /= 10) cnt++;
	for (i = 1;i <= cnt;++i, j *= 10) ans += 9 * j * i;
	ans += (v + 1 - j) * i;
	cout << ans;
	return 0;
}