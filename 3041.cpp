#include <iostream>
#include <cmath>
using namespace std;

char sym[4][4]; 

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 4; ++i) cin >> sym[i];
	int ans = 0; 
	for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j)
		if (sym[i][j] != '.') ans += (abs((sym[i][j] - 'A') / 4 - i) + abs((sym[i][j] - 'A') % 4 - j)); 
	cout << ans;
	return 0; 
}