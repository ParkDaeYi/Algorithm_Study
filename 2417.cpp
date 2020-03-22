#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

llt n, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	 ans = sqrt(n);
	 if (pow(ans, 2) < n) cout << ans + 1;
	 else cout << ans;
	return 0;
}