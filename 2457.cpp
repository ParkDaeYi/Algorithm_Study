#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0;i < n;++i) {
		pii a, b;
		cin >> a.first >> a.second >> b.first >> b.second;
		v.push_back(pii(a.first * 100 + a.second, b.first * 100 + b.second));
	}
	sort(v.begin(), v.end());
	int prev = 0, ans = 0, idx = -1, sz = v.size();
	for (int i = 301;i <= 1130 && idx < n;i = prev) {
		bool flag = 0;
		idx++;
		for (int j = idx;j < sz;++j) {
			if (v[j].first > i) break;
			else if (prev < v[j].second) {
				prev = v[j].second;
				idx = j;
				flag = 1;
			}
		}
		if (flag) ans++;
		else {
			cout << 0;
			return 0;
		}
	}
	cout << ans;
	return 0;
}