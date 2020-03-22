#include <iostream>
using namespace std;

int p, g, parent[100001], ans;

int getParent(int);
void unite(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> g >> p;
	for (int i = 1; i <= g; ++i) parent[i] = i;
	for (int i = 0, n; i < p; ++i) {
		cin >> n;
		int chk = getParent(n);
		if (chk) {
			ans++;
			unite(chk, chk - 1);
		}
		else break;
	}
	cout << ans;
	return 0;
}

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void unite(int a, int b) {
	parent[parent[a]] = parent[b];
}