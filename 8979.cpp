#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct point {
	int idx, a, b, c;
	bool operator<(const point& p) const {
		return a != p.a ? p.a < a : b != p.b ? p.b < b : p.c < c;
	}
};
int n, m;
vector<point> arr;

bool chk(point& p1, point& p2) {
	if (p1.a == p2.a && p1.b == p2.b && p1.c == p2.c) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0, idx, a, b, c;i < n;++i) {
		cin >> idx >> a >> b >> c;
		arr.push_back({ idx,a,b,c });
	}
	sort(arr.begin(), arr.end());
    // 연산자 오버로딩을 쓰지 않고
    // cmp 구조체를 통해 정렬을 한다면
    // idx 가 m이 되었을 때 탈출하면 됨
    // 그때 i + 1 이 답임
	int ans = 0, tmp = 0;
	for (int i = 0;i < n - 1;++i) {
		if (arr[i].idx == m) break;
		if (chk(arr[i], arr[i + 1])) tmp++;
		else ans += tmp + 1, tmp = 0;
	}
	cout << ans + 1;
	return 0;
}