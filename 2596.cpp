#include <iostream>
#include <vector>
using namespace std;

char alpha[8];
int code[8][6] = {
	{0,0,0,0,0,0}, // A
	{0,0,1,1,1,1}, // B
	{0,1,0,0,1,1}, // C
	{0,1,1,1,0,0}, // D
	{1,0,0,1,1,0}, // E
	{1,0,1,0,0,1}, // F
	{1,1,0,1,0,1}, // G
	{1,1,1,0,1,0} // H
};
int n, arr[10][6];
vector<char> ans;

int sol(int a[]) {
	int ret = -1;
	for (int i = 0;i < 8;++i) {
		int cnt = 0;
		for (int j = 0;j < 6;++j) {
			if (a[j] != code[i][j]) cnt++;
			if (cnt > 1) break;
		}
		if (!cnt) return i;
		if (cnt == 1) ret = i;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0;i < 8;++i) alpha[i] = 'A' + i;
	cin >> n;
	char c;
	for (int i = 0;i < n;++i) for (int j = 0;j < 6;++j) {
		cin >> c;
		arr[i][j] = c - '0';
	}
	for (int i = 0;i < n;++i) {
		int idx = sol(arr[i]);
		if (idx == -1) {
			cout << i + 1;
			return 0;
		}
		ans.push_back(alpha[idx]);
	}
	for (char c : ans) cout << c;
	return 0;
}