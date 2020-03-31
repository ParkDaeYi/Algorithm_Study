#include <iostream>
#define MAX 10
using namespace std;

int mp[101][101], n, x, y, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> x >> y;
		for (int i = x;i < x + MAX;++i) 
			for (int j = y;j < y + MAX;++j) {
				if (mp[i][j]) continue;
				mp[i][j]++;
				ans++;
			}	
	}
	cout << ans;
	return 0;
}