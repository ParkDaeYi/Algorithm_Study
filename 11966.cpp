#include <iostream>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	n& (n - 1) ? cout << 0 : cout << 1;
	return 0;
}