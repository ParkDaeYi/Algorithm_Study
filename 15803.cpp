#include <iostream>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;

pii arr[3];

int ccw(pii a, pii b, pii c) { return a.x * b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c.x + c.y * a.x); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0;i < 3;++i) cin >> arr[i].x >> arr[i].y;
	if (!ccw(arr[0], arr[1], arr[2])) cout << "WHERE IS MY CHICKEN?";
	else cout << "WINNER WINNER CHICKEN DINNER!";
	return 0;
}