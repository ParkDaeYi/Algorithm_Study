#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char alpa[16], result[16];

void dfs(int, int, int, int);
bool A(char);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C;
	for (int i = 0; i < C; ++i) cin >> alpa[i];
	sort(alpa, alpa + C);
	dfs(0, 0, 0, 0);
	return 0;
}

void dfs(int a, int b,int idx1,int idx2) {
	if (idx2 == L) {
		if (a > 0 && b > 1) {
			for (int i = 0; i < L; ++i) cout << result[i];
			cout << "\n";
		}
		return;
	}
	for (int i = idx1; i < C; ++i) {
		result[idx2] = alpa[i];
		if (A(alpa[i])) dfs(a + 1, b, i + 1, idx2 + 1);
		else dfs(a, b + 1, i + 1, idx2 + 1);
	}
}

bool A(char a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') return true;
	return false;
}