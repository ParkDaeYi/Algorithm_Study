#include <iostream>
#include <stack>
#define MAX 1000000
using namespace std;
typedef pair<int, int> pii;

pii info[MAX];
int arr[MAX], ans[MAX], n;

int lower_BD(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];

	int itr_ans = 0, itr_arr = 1;
	ans[0] = arr[0];
	info[0] = make_pair(0, arr[0]);
	while (itr_arr < n) {
		if (ans[itr_ans] < arr[itr_arr]) {
			ans[++itr_ans] = arr[itr_arr];
			info[itr_arr] = make_pair(itr_ans, arr[itr_arr]);
		}
		else {
			int p = lower_BD(0, itr_ans, arr[itr_arr]);
			ans[p] = arr[itr_arr];
			info[itr_arr] = make_pair(p, arr[itr_arr]);
		}
		++itr_arr;
	}
	cout << itr_ans + 1 << '\n';

	int t = itr_ans;
	stack<int> st;
	for (int i = n - 1; i >= 0; --i) {
		if (info[i].first == t) {
			st.push(info[i].second);
			--t;
		}
	}
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	return 0;
}

int lower_BD(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (ans[mid] < target) left = mid + 1;
		else right = mid;
	}
	return right;
}
