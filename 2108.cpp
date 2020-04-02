#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, cnt[8001], num;
int min_n = 5000, max_n = -5000, mid_n, maxCnt, sum;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		sum += num;
		cnt[num + 4000]++;
		if (maxCnt <= cnt[num + 4000]) {
			if (maxCnt < cnt[num + 4000]) v.clear();
			v.push_back(num);
			maxCnt = cnt[num + 4000];
		}
		if (min_n > num) min_n = num;
		if (max_n < num) max_n = num;
	}
	for (int i = min_n + 4000, tmp = 0; i < 8001; i++) {
		if (!cnt[i]) continue;
		if (tmp + cnt[i] >= (n + 1) / 2) {
			mid_n = i - 4000;
			break;
		}
		tmp += cnt[i];
	}

	cout.precision(0);
	cout << fixed << (double)sum / n << "\n";
	cout << mid_n << "\n";
	sort(v.begin(), v.end());
	if (v.size() == 1) cout << v[0] << "\n";
	else cout << v[1] << "\n";
	cout << max_n - min_n << "\n";
	return 0;
}