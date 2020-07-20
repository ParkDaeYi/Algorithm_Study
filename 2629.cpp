#include <iostream>
#include <cmath>
#define INF 15001
using namespace std;

int n, m, arr[30];
bool ans[INF], tmp[INF];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	ans[0] = tmp[0] = 1;
	for (int i = 0, left, right; i < n; ++i) {
		// 양팔저울 왼쪽에 구슬이 있다고 가정
		// j의 값은 현재 오른쪽에 있을 수 있는 추의 무게
		// ==> 추가 사용되었을 수도 있고 사용되지 않았을 수도 있음
		for (int j = 0; j < INF; ++j) {
			if (!ans[j]) continue;
			// left : 구슬이 있는 곳에 추를 올릴 경우
			// right : 구슬 반대 방향에 추를 올릴 경우
			left = abs(j - arr[i]), right = j + arr[i];
			if (left < INF) tmp[left] = 1;
			if (right < INF) tmp[right] = 1;
		}
		for (int j = 0; j < INF; ++j) ans[j] = tmp[j];	// 현재 상황에서 가능한 경우를 추가
	}
	cin >> m;
	while (m--) {
		int p;
		cin >> p;
		cout << (p < INF && ans[p] ? "Y " : "N ");
	}
	return 0;
}