#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int llt;

class box {
public:
	int start, end, gap;
	box(int s = -1, int e = -1, int g = -1) :start(s), end(e), gap(g) {}
};

int n, k, d, ans;
box boxs[1000000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> d;
	for (int i = 0; i < k; ++i) cin >> boxs[i].start >> boxs[i].end >> boxs[i].gap;
	int left = 1, right = n, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		llt cnt = 0;
		for (int i = 0; i < k; ++i) {
			int tmp = min(boxs[i].end, mid);
			if (tmp >= boxs[i].start) cnt += (tmp - boxs[i].start) / boxs[i].gap + 1;
		}
		if (cnt < d) left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
	return 0;
}