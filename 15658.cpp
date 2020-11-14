#include <iostream>
using namespace std;

int n, arr[11], op[4], mx = -1e9, mn = 1e9;

void calc(int idx, int p, int s, int m, int d, int res) {
	if (idx == n) {
		mx = mx < res ? res : mx;
		mn = mn < res ? mn : res;
		return;
	}
	if (p > 0) calc(idx + 1, p - 1, s, m, d, res + arr[idx]);
	if (s > 0) calc(idx + 1, p, s - 1, m, d, res - arr[idx]);
	if (m > 0) calc(idx + 1, p, s, m - 1, d, res * arr[idx]);
	if (d > 0) calc(idx + 1, p, s, m, d - 1, res / arr[idx]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;++i) cin >> arr[i];
	for (int i = 0;i < 4;++i) cin >> op[i];	// + - * /
	calc(1, op[0], op[1], op[2], op[3], arr[0]);
	cout << mx << '\n' << mn;
	return 0;
}