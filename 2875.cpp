#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	cout << min(min(n / 2, m), (n + m - k) / 3);
	return 0;
}