#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 300001
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> pos;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, x, r; i < n; ++i) {
		cin >> x >> r;
		pos.push_back(pii(x - r, 1));
		pos.push_back(pii(x + r, 0));
	}
	sort(pos.begin(), pos.end(), [](const pii& a, const pii& b) {
		return a.first == b.first ? a.second < b.second:a.first < b.first;
	});
	stack<pii> st;
	int ans = 1, prev = 0;
	for (pii p : pos) {
		if (st.empty()) {
			st.push(pii(p.first, 0));
			prev = p.first;
		}
		else if (p.second) {
			if (p.first == prev) {
				pii tmp = st.top(); st.pop();
				if (tmp.second != -1)tmp.second = 1;
				st.push(tmp);
				st.push(pii(p.first, 0));
			}
			else {
				pii tmp = st.top(); st.pop();
				tmp.second = -1;
				st.push(tmp);
				st.push(pii(p.first, 0));
				prev = p.first;
			}
		}
		else {
			if (st.top().second == 1 && prev == p.first) ans += 2;
			else ans++;
			st.pop();
			prev = p.first;
		}
	}
	cout << ans;
	return 0;
}