#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int llt;
typedef pair<llt, llt> pll;

llt ans;
int n;
pll tree[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> tree[i].second;
	for (int i = 0; i < n; ++i) cin >> tree[i].first;
	sort(tree, tree + n);
	for (int i = 0; i < n; ++i) ans += tree[i].second + tree[i].first * i;
	cout << ans;
	return 0;
}