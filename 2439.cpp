#include <iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) cout << ' ';
		for (int j = n - 1; j >= n - i - 1; --j) cout << '*';
		cout << '\n';
	}
	return 0;
}