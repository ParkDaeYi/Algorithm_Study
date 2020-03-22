#include <iostream>
using namespace std;

int n, x, s;
char sym[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) {
		cin >> sym;
		if (sym[1] == 'd') {
			cin >> x;
			s |= (1 << (x - 1));
		}
		else if (sym[1] == 'e') {
			cin >> x;
			s &= ~(1 << (x - 1));
		}
		else if (sym[1] == 'h') {
			cin >> x;
			(s & 1 << (x - 1)) ? cout << 1 : cout << 0;
			cout << '\n';
		}
		else if (sym[1] == 'o') {
			cin >> x;
			s ^= (1 << (x - 1));
		}
		else if (sym[1] == 'l')
			s = (1 << 20) - 1;
		else s = 0;
	}
	return 0;
}