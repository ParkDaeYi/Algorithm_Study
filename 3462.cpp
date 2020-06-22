#include <iostream>
using namespace std;

int d, n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> d;
	for (int i = 0; i < d; i++) {
		cin >> n >> m;
		if ((n - m) & (m - 1) / 2) cout << 0 << '\n';	// 왜 이건지 모르겠음...............
		else cout << 1 << '\n';
	}
	return 0;
}