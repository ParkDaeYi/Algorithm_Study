#include <iostream>
using namespace std;

int cost[1000000], ans[1000000], n;

int lower_bd(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> cost[i];
	int cost_idx = 1, ans_idx = 0;
	ans[0] = cost[0];
	while (cost_idx < n) {
		if (ans[ans_idx] < cost[cost_idx]) ans[++ans_idx] = cost[cost_idx];
		else {
			int itr = lower_bd(0, ans_idx, cost[cost_idx]);
			ans[itr] = cost[cost_idx];
		}
		++cost_idx;
	}
	cout << ans_idx + 1;
	return 0;
}

int lower_bd(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (ans[mid] < target) left = mid + 1;
		else right = mid;
	}
	return right;
}