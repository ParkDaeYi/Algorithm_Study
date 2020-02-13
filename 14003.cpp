#include <iostream>
<<<<<<< HEAD
#include <stack>
#define MAX 1000000
using namespace std;
typedef pair<int, int> pii;

pii info[MAX];
int arr[MAX], ans[MAX], n;

int lower_BD(int, int, int);
=======
#include <string>
#include <stack>
using namespace std;

string str1, str2;
int ans, dp[1001][1001];
>>>>>>> fbc04d91c20c479b7c19aed9d7bd853e6c7378a6

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

<<<<<<< HEAD
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
=======
	cin >> str1 >> str2;
	int sz1 = str1.length(), sz2 = str2.length();
	for (int i = 1; i <= sz1; ++i) {
		for (int j = 1; j <= sz2; ++j) {
			if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;		
			else dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];	
		}
	}
	cout << dp[sz1][sz2] << '\n';
	stack<char> st;
	for (int i = sz1, j = sz2; i > 0 && j > 0;) {
		if (str1[i - 1] == str2[j - 1]) {
			st.push(str1[i - 1]); --i, --j;
		}
		else {
			if (dp[i - 1][j] > dp[i][j - 1]) --i;
			else --j;
		}
	}
	while (!st.empty()) {
		cout << st.top();
>>>>>>> fbc04d91c20c479b7c19aed9d7bd853e6c7378a6
		st.pop();
	}
	return 0;
}
<<<<<<< HEAD

int lower_BD(int left, int right, int target) {
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (ans[mid] < target) left = mid + 1;
		else right = mid;
	}
	return right;
}
=======
>>>>>>> fbc04d91c20c479b7c19aed9d7bd853e6c7378a6
