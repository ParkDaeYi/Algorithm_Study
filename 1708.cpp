#include <iostream>
#include <stack>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long int llt;

class info {
public:
	int x, y, p, q;
	info(int x = 0, int y = 0) :x(x), y(y), p(0), q(0) {}
}pos[MAX];
int n;
stack<int> st;

bool cmp(const info& a, const info& b) {
	//반시계 방향으로 정렬, ccw임
	//(xa - x0)(yb - y0) - (ya - y0)(xb - x0) 가 양수이면 반시계 방향이므로
	//(xa - x0)(yb - y0) > (ya - y0)(xb - x0) 를 성립해야함
	if (1LL * a.q * b.p != 1LL * a.p * b.q) return 1LL * a.q * b.p < 1LL * a.p * b.q;
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

llt ccw(info a, info b, info c) {
	//(x2 - x1)(y3 - y1) - (y2 - y1)(x3 - x1)
	//x1y2 + x2y3 + x3y1 - (y1x2 + y2x3 + y3x1) 가 양수이면 반시계 음수이면 시계 방향
	return 1LL * (a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> pos[i].x >> pos[i].y;
	sort(pos, pos + n, cmp);
	//xi - x0, yi - y0 로 상대 위치를 계산
	for (int i = 1; i < n; ++i) pos[i].p = pos[i].x - pos[0].x, pos[i].q = pos[i].y - pos[0].y;
	//기준 점을 제외하고 정렬
	sort(pos + 1, pos + n, cmp);
	st.push(0); st.push(1);
	int next = 2;
	while (next < n) {
		while (st.size() > 1) {
			int first, second;
			second = st.top();
			st.pop();
			first = st.top();
			//first, second, next 가 반시계 방향이라면 second를 push
			//시계 방향이라면 반복
			if (ccw(pos[first], pos[second], pos[next]) > 0) {
				st.push(second);
				break;
			}
		}
		st.push(next++);
	}
	cout << st.size();
	return 0;
}