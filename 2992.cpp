#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string str; cin >> str;
	// 다음 순열이 없을 경우 0을 반환하는 듯
	bool chk = next_permutation(str.begin(), str.end());
	if (chk) cout << str;
	else cout << 0;
	return 0;
}