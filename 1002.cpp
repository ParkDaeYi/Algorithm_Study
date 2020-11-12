#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;	cin >> n;
	while (n--) {
		int x1, y1, r1, x2, y2, r2;	// r 은 지름
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int dx = x1 - x2, dy = y1 - y2;
		int d = dx * dx + dy * dy;	// d 는 원 사이의 거리
		int sum = (r1 + r2) * (r1 + r2), sub = (r1 - r2) * (r1 - r2);
		// 두 원이 완전히 일치하는 경우
		if (!d && r1 == r2) cout << -1;
		// |r1 - r2| < d < r1 + r2: 원이 두 점에서 만나는 경우
		else if (sub < d && d < sum) cout << 2;
		// r1 + r2 == d: 교점 1개 (외접)
		// |r1 - r2| == d: 교점 1개 (내접) 대신 d가 0이면 안됨
		else if (d == sum || (d == sub && d)) cout << 1;
		// r1 + r2 < d: 교점 없음
		// |r1 - r2| > d: 교점 없음 (큰 원 안에 작은 원 포함)
		else cout << 0;
		cout << '\n';
	}
	return 0;
}