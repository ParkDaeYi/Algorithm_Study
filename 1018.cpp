#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string B[8] = {
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"}
};
string W[8] = {
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"},
{"WBWBWBWB"},
{"BWBWBWBW"}
};
int n, m, ans = 1e9 + 1;
string str[50];

int w_cnt(int, int);
int b_cnt(int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> str[i];
	for (int i = 0; i + 7 < n; ++i) {
		for (int j = 0; j + 7 < m; ++j) {
			ans = min(ans, min(w_cnt(i, j), b_cnt(i, j)));
		}
	}
	cout << ans;
	return 0;
}

int w_cnt(int y,int x) {
	int cnt = 0;
	for (int i = y; i < 8 + y; ++i) {
		for (int j = x; j < 8 + x; ++j) {
			if (W[i - y][j - x] != str[i][j]) ++cnt;
		}
	}
	return cnt;
}

int b_cnt(int y, int x) {
	int cnt = 0;
	for (int i = y; i < 8 + y; ++i) {
		for (int j = x; j < 8 + x; ++j) {
			if (B[i - y][j - x] != str[i][j]) ++cnt;
		}
	}
	return cnt;
}