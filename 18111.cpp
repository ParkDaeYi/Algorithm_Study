#include <iostream>
using namespace std;

int n, m, b, arr[257];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> b;
	for (int i = 0, x; i < n * m; ++i) {
		cin >> x;
		arr[x]++;
	}
	int anst = 1e9, ansh = 0;
	for (int i = 256; i >= 0; --i) {
		int t = 0, blk = b;
		for (int j = 256; j > i; --j) {
			t += arr[j] * (j - i) * 2;
			blk += arr[j] * (j - i);
		}
		for (int j = 0; j < i; ++j) {
			t += arr[j] * (i - j);
			blk -= arr[j] * (i - j);
		}
		if (blk < 0) continue;
		if (t < anst) {
			anst = t;
			ansh = i;
		}
	}
	cout << anst << ' ' << ansh;
	return 0;
}