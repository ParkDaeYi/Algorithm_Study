#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[15], ans[15];

bool check(char c) {
	// 모음인지 체크
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
	return 0;
}

void dfs(int depth, int idx, int con, int vow) {
	// 자음: Consonant , 모음: Vowel
	if (depth == L) {
		// 모음이 최소 하나 이상, 자음은 최소 두 개 이상
		if (con > 0 && vow > 1) {
			for (int i = 0; i < L; ++i) cout << ans[i];
			cout << '\n';
		}
		return;
	}
	for (int i = idx; i < C; ++i) {
		// 정렬된 문자열을 선호하므로 idx를 사용하여 처리
		ans[depth] = arr[i];	// L 만큼만 배열에 넣어야하므로 depth를 사용
		if (check(arr[i])) dfs(depth + 1, i + 1, con + 1, vow);	// 모음일 경우 con + 1
		else dfs(depth + 1, i + 1, con, vow + 1);	// 자음일 경우 vow + 1
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; ++i) cin >> arr[i];
	sort(arr, arr + C);	// 정렬된 문자열을 선호하니까 정렬해줌
	dfs(0, 0, 0, 0);

	return 0;
}