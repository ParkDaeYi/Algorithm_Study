#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int time[10001], n, q, tmp;
	cin >> n >> q;
	for (int i = 0, idx = 0, t = 1; i < n; ++i) {
		cin >> tmp;
		for (int j = 0; j < tmp; ++j) time[idx++] = t;
		++t;
	}
	for (int i = 0; i < q; ++i) {
		cin >> tmp;
		cout << time[tmp] << '\n';
	}
	return 0;
}