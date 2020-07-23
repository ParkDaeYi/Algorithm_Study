#include <iostream>
using namespace std;

int n, m, p[1000001];

int getParent(int x) {
	if (x == p[x]) return x;
	return p[x] = getParent(p[x]);
}

void merge(int a, int b) {
	// 부모 값을 가져옴
	a = getParent(a);
	b = getParent(b);
	// 큰 값에 넣어줌 (그냥 넣어도 상관은 없음)
	if (a > b) swap(a, b);
	p[b] = a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) p[i] = i;
	for (int i = 0, x, a, b; i < m; ++i) {
		cin >> x >> a >> b;
		if (x) cout << (getParent(a) == getParent(b) ? "YES\n" : "NO\n");
		else merge(a, b);
	}
	return 0;
}