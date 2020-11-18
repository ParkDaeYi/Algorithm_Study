#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str; cin >> str;
	int arr[10] = { 0, }, n = str.length();
	for (int i = 0;i < n;++i) arr[i] = str[i] - '0';
	sort(arr, arr + n, greater<int>());
	for (int i = 0;i < n;++i) cout << arr[i];
	return 0;
}