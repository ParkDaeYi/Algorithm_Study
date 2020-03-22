#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX_N 20020
using namespace std;
typedef pair<int, int> pii;

class point {
public:
	int x, y1, y2;
	point(int x = 0, int y1 = 0, int y2 = 0) :x(x), y1(y1), y2(y2) {}
	bool operator < (const point& p) const {
		return x < p.x;
	}
};
int t, n, k, seg[1 << 21];
vector<pii> pos[MAX_N];
vector<point> line;
vector<int> reY;

void update_tree(int sz, int y, int val) { for (int node = sz + y - 1; node > 0; node /= 2) seg[node] += val; }

int sum(int node, int start, int end, int left, int right) {
	if (end < left || right < start) return 0;
	if (left <= start && end <= right) return seg[node];
	int mid = (start + end) >> 1;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		line.clear();
		reY.clear();
		cin >> n;
		for (int i = 0, x, y; i < n; ++i) {
			pos[i].clear();
			cin >> k;
			while (k--) {
				cin >> x >> y;
				pos[i].push_back(pii(x, y));
				reY.push_back(y);
			}
			pos[i].push_back(pos[i][0]);
			for (int j = 0; j < pos[i].size() - 1; ++j) {
				if (pos[i][j].first == pos[i][j + 1].first) 
					line.push_back(point(pos[i][j].first, pos[i][j].second, pos[i][j + 1].second));				
			}
		}
		sort(reY.begin(), reY.end());
		reY.erase(unique(reY.begin(), reY.end()), reY.end());
		for (int i = 0; i < line.size(); ++i) {
			line[i].y1 = lower_bound(reY.begin(), reY.end(), line[i].y1) - reY.begin() + 1;
			line[i].y2 = lower_bound(reY.begin(), reY.end(), line[i].y2) - reY.begin() + 1;
		}
		sort(line.begin(), line.end());
		int ans = 0;
		const int sz = pow(2, (int)log2(reY.size() - 1) + 1);
		for (int i = line.size() - 1; i >= 0; --i) {
			update_tree(sz, line[i].y1, 1);
			update_tree(sz, line[i].y2, -1);
			int res = 0;
			if (line[i].y1 < line[i].y2) res = sum(1, 1, sz, 1, line[i].y1);
			ans = max(ans, res);
		}
		cout << ans << '\n';
		fill(seg, seg + sz + sz, 0);
	}
	return 0;
}