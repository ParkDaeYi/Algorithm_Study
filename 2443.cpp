#include <iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) cout << ' ';
		for (int j = i; j < n; ++j) cout << '*';
		for (int j = n; j < n + n - 1 - i; ++j) cout << '*';
		cout << '\n';
	}
	return 0;
}