#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, char> pic;
typedef pair<int, int> pii;

pic arr[5];
int cnt[10], ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0;i < 5;++i) {
		cin >> arr[i].second >> arr[i].first;
		cnt[arr[i].first]++;	// cnt 배열을 통해 동일한 숫자를 파악함
	}
	sort(arr, arr + 5);
	int maxNum = arr[4].first;
	bool color = true, seq = true;
	char tmp = arr[0].second;
	for (int i = 1;i < 5;++i) {
		if (tmp != arr[i].second) color = false;
		if (arr[i].first != arr[i - 1].first + 1) seq = false;
	}
	if (color) ans = 600 + maxNum;
	if (seq) ans = 500 + maxNum;
	if (color && seq) ans = 900 + maxNum;

	vector<pii> vcnt;
	for (int i = 1;i < 10;++i) if (cnt[i]) vcnt.push_back({ cnt[i],i });
	sort(vcnt.begin(), vcnt.end(), greater<pii>());
	if (vcnt[0].first >= 4) ans = 800 + vcnt[0].second;
	else if (vcnt[0].first == 3) {
		if (vcnt[1].first == 2) ans = 700 + vcnt[0].second * 10 + vcnt[1].second;
		else ans = max(ans, 400 + vcnt[0].second);
	}
	else if (vcnt[0].first == 2) {
		if (vcnt[1].first == 2) {
			int m = max(vcnt[0].second, vcnt[1].second);
			int n = min(vcnt[0].second, vcnt[1].second);
			ans = max(ans, 300 + m * 10 + n);
		}
		else ans = max(ans, 200 + vcnt[0].second);
	}
	else ans = max(ans, 100 + maxNum);
	cout << ans;
	return 0;
}