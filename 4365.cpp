#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int poker[53], shuffles[101][53], n, t;
string suit[4] = { "Clubs","Diamonds","Hearts","Spades" };
string card[13] = { "2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace" };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 1;i <= n;++i) for (int j = 1;j < 53;++j) cin >> shuffles[i][j];
	for (int i = 1;i < 53;++i) poker[i] = i - 1;
	char input[50];
	while (cin >> input && strlen(input)) {
		int num = atoi(input);
		int nxt[53];
		for (int i = 1;i < 53;++i) nxt[i] = poker[shuffles[num][i]];
		for (int i = 1;i < 53;++i) poker[i] = nxt[i];
		for (int i = 1;i < 53;++i) cout << card[poker[i] % 13] << " of " << suit[poker[i] / 13] << '\n';
		cout << '\n';
	}
	return 0;
}