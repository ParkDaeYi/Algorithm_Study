#include <stdio.h>
#pragma warning(disable:4996)

int n, ans = 1e9;
char s1[100001], s2[100001], e[100001];

void simul(char s[], int cur, int cnt) {
	if (cur == n - 1) {
		if (s[cur - 1] == e[cur - 1] && s[cur] == e[cur]) ans = ans > cnt ? cnt : ans;
		for (int i = cur - 1; i <= cur; ++i) s[i] == '0' ? s[i] = '1' : s[i] = '0';
		if (s[cur - 1] == e[cur - 1] && s[cur] == e[cur]) ans = ans > cnt + 1 ? cnt + 1 : ans;
		return;
	}
	if (s[cur - 1] == e[cur - 1]) simul(s, cur + 1, cnt);
	for (int i = cur - 1; i <= cur + 1; ++i) s[i] == '0' ? s[i] = '1' : s[i] = '0';
	if (s[cur - 1] == e[cur - 1]) simul(s, cur + 1, cnt + 1);
}

int main() {

	scanf("%d\n", &n);
	scanf("%s\n", s1);
	scanf("%s", e);
	for (int i = 0; i < n; ++i) s2[i] = s1[i];
	for (int i = 0; i <= 1; ++i) s2[i] == '0' ? s2[i] = '1' : s2[i] = '0';
	simul(s1, 1, 0);
	simul(s2, 1, 1);
	printf("%d", ans == 1e9 ? -1 : ans);
	return 0;
}