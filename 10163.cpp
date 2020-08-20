#include <iostream>
using namespace std;

int n, map[102][102];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1, a, b, c, d;i <= n;++i) {
		cin >> a >> b >> c >> d;
		for (int j = a;j < a + c;++j) for (int k = b;k < b + d;++k) map[j][k] = i;
	}
	for (int i = 1;i <= n;++i) {
		int cnt = 0;
		for (int j = 0;j < 102;++j) for (int k = 0;k < 102;++k) if (i == map[j][k]) cnt++;
		cout << cnt << '\n';
	}
	return 0;
}