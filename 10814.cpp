#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

pii a[100000];
string b[100000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0;i < n;++i) {
		int x;
		cin >> x >> b[i];
		a[i] = pii(x, i);
	}
	sort(a, a + n);
	for (int i = 0;i < n;++i) cout << a[i].first << ' ' << b[a[i].second] << '\n';
	return 0;
}