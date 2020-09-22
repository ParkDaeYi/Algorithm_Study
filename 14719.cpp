// 시키는대로 짠 코드
// s랑 e로 값을 구함
#include <iostream>
using namespace std;

int h, w, arr[501][501], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> h >> w;
	for (int i = 0, x;i < w;++i) {
		cin >> x;
		for (int j = 0;j < x;++j) arr[j][i] = 1;
	}
	for (int i = 0;i < h;++i) {
		int s = 0, e = 0;
		for (int j = 0;j < w;++j) {
			if (arr[i][j]) {
				s = j;
				break;
			}
		}
		for (int j = w - 1;j > s;--j) {
			if (arr[i][j]) {
				e = j;
				break;
			}
		}
		for (int j = s + 1;j <= e;++j) {
			if (!arr[i][j]) ans++;
		}
	}
	cout << ans;
	return 0;
}


// I 좌 우 에서 각각 큰 값을 추출
// 그 중 가장 낮은 높이와 현재 I 차이 값을 ans에 더함
#include <algorithm>

int h, w, a[501], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> h >> w;
	for (int i = 0;i < w;++i) cin >> a[i];
	for (int i = 1;i < w;++i) {
		int l = 0, r = 0;
		for (int j = 0;j < i;++j) l = max(l, a[j]);
		for (int j = w - 1;j > i;--j) r = max(r, a[j]);
		ans += max(0, min(l, r) - a[i]);
	}
	cout << ans;
	return 0;
}