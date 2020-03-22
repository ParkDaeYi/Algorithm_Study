#include <iostream>
using namespace std;

int l, p, v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 1;; i++) {
		cin >> l >> p >> v;
		if (!l && !p && !v) return 0;
		int op = (v % p) > l ? l : v % p;
		int ans = (v / p) * l + op;
		cout << "Case " << i << ": " << ans << '\n';
	}
}