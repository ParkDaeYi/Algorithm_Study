#include <iostream>
using namespace std;

int t, idx, m;

int fisano() {
	int cnt = 0, m1 = 0, m2 = 1;
	while (1) {
		int tmp = m1;
		m1 = m2;
		m2 = (tmp + m1) % m;
		cnt++;
		if (!m1 && m2 == 1) return cnt;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> idx >> m;
		cout << idx << ' ' << fisano() << '\n';
	}
	return 0;
}