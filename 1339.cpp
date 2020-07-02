#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int n, alpha[26], ans;
vector<string> arr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		arr.push_back(str);
	}

	// 수의 합을 최대로 만들어야 하는게 목표
	for (int i = 0; i < n; ++i) for (int j = 0; j < arr[i].size(); ++j) 
		alpha[arr[i][j] - 'A'] += pow(10, arr[i].size() - 1 - j);	// 해당 알파벳을 10의 승수로 저장
	sort(alpha, alpha + 26, greater<int>());	// 내림차순으로 정렬

	for (int i = 9, j = 0; i > 0 && j < 26; --i, ++j) {
		if (!alpha[j]) break;
		ans += alpha[j] * i;
	}
	cout << ans;

	return 0;
}