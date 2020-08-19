#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, s, p;
	cin >> n >> s >> p;
	int ans = 1, chk = 1;
	for (int i = 0, num;i < n;++i) {
		cin >> num;
		if (num > s) ans++;
		if (num >= s) chk++;
	}
	if (ans > p || chk > p) cout << -1;
	else cout << ans;
	return 0;
}