#include <iostream>
using namespace std;

char mp[51][51];
int n, m, mp_end, ans = 1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	mp_end = n > m ? m : n;
	for (int i = 0;i < n;++i) cin >> mp[i];
	for (int i = 0;i < n;++i) 
		for (int j = 0;j < m;++j) 
			for (int k = 1;k <= mp_end;++k) {
				if (i + k >= n || j + k >= m) break;
				if (mp[i][j] == mp[i][j + k] && mp[i][j] == mp[i + k][j] && mp[i][j] == mp[i + k][j + k]) 
					ans = ans > k + 1 ? ans : k + 1;		
			}
	cout << ans * ans;
	return 0;
}