#include <iostream>
#define MAX_N 1000001
using namespace std;

int n, m, parent[MAX_N];

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void merge(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) parent[a] = b;
	else parent[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1;i < n + 1;++i) parent[i] = i;
	while (m--) {
		int op, a, b;
		cin >> op >> a >> b;
		if (!op) merge(a, b);
		else cout << (getParent(a) != getParent(b) ? "NO\n" : "YES\n");
	}
	return 0;
}