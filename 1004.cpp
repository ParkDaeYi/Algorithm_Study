#include <iostream>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;

int T, n;

bool ck(pii a, pii b, int r) {
	int d = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	// a와 b 정점 사이의 거리와 b의 지름 비교
	return d > r * r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	while (T--) {
		pii s, e;
		cin >> s.x >> s.y >> e.x >> e.y >> n;
		int cnt = 0;
		while (n--) {
			pii tmp; int r;
			cin >> tmp.x >> tmp.y >> r;
			bool f1 = ck(s, tmp, r), f2 = ck(e, tmp, r);
			if (f1 != f2) cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}