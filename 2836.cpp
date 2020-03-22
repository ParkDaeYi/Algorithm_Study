#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 300001
using namespace std;
typedef long long int llt;
typedef pair<int, int> pii;

vector<pii> pos;
llt m;
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0, x1, x2; i < n; ++i) {
		cin >> x1 >> x2;
		if (x1 > x2) pos.push_back(pii(x2, x1));
	}
	sort(pos.begin(), pos.end());
	llt len = 0;
	int prv = -1;
	for (pii p : pos) {
		if (prv < p.first) len += p.second - p.first;
		else if (prv < p.second) len += p.second - prv;
		prv = max(prv, p.second);
	}
	cout << m + len + len;
	return 0;
}