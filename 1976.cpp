#include <iostream>
using namespace std;

int city[201], n, m;

int getParent(int x) {
	if (city[x] == x) return x;
	else return city[x] = getParent(city[x]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i < n + 1; ++i) city[i] = i;

	for (int i = 1; i < n + 1; ++i)
		for (int j = 1, tmp; j < n + 1; ++j) {
			cin >> tmp;
			if (tmp) {
				int a = getParent(i);
				int b = getParent(j);
				if (a != b) {
					city[a] = b;
				}
			}
		}

	int a, b;
	cin >> a;
	a = getParent(a);
	for (int i = 1; i < m; ++i) {
		cin >> b;
		b = getParent(b);
		if (a != b) {
			cout << "NO";
			return 0;
		}
		a = b;
	}
	cout << "YES";
	return 0;
}