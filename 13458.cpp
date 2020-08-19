#include <iostream>
#define N 1000000
using namespace std;
typedef long long ll;

int n, arr[N], b, c;
ll ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;++i) cin >> arr[i];
	cin >> b >> c;
	for (int i = 0;i < n;++i) {
		arr[i] -= b;
		if (arr[i] <= 0) continue;
		ans += arr[i] / c + (arr[i] % c != 0);
	}
	cout << ans + n;
	return 0;
}