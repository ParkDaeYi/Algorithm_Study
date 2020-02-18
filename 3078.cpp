#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef long long int llt;

int n, m;
llt ans;
vector<int> fr[21];

llt upper_bd(int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string str;
		cin >> str;
		fr[str.length()].push_back(i);
	}
	for (int i = 2; i < 21; ++i) {
		if (!fr[i].empty()) {
			int sz = fr[i].size();
			sort(fr[i].begin(), fr[i].end());
			for (int j = 0; j < sz - 1; ++j) {
				llt itr = upper_bd(i, j, sz, fr[i][j] + m) - 1;
				ans += itr - j;
			}
		}
	}
	cout << ans;
	return 0;
}

llt upper_bd(int idx, int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (fr[idx][mid] <= target) left = mid + 1;
		else right = mid;
	}
	return right;
}