#include <iostream>
using namespace std;

int x[3], y[3];

int ccw();

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < 3; ++i) cin >> x[i] >> y[i];
	cout << ccw();
	return 0;
}

int ccw() {
	//(x2 - x1)(y3 - y1) - (y2 - y1)(x3 - x1)
	int ret = (x[1] - x[0]) * (y[2] - y[0]) - (y[1] - y[0]) * (x[2] - x[0]);
	return ret = !ret ? 0 : ret > 0 ? 1 : -1;
}