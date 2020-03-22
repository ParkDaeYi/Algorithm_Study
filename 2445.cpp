#include <iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) cout << '*';
		for (int j = i + 1; j < n + n - i - 1; ++j) cout << ' ';
		for (int j = 0; j <= i; ++j) cout << '*';
		cout << '\n';
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i; ++j) cout << '*';
		for (int j = 0; j < i + i; ++j) cout << ' ';
		for (int j = 0; j < n - i; ++j) cout << '*';
		cout << '\n';
	}
	return 0;
}