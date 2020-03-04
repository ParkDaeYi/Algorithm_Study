#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> pii;

int n;
vector<pii> vec;

void hanoi(int, int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	hanoi(n, 1, 2, 3);
	cout << vec.size() << '\n';
	for (pii a : vec) cout << a.first << ' ' << a.second << '\n';
	return 0;
}

void hanoi(int num, int from, int by, int to) {
	if (num == 1) vec.push_back({ from,to });
	else {
		hanoi(num - 1, from, to, by);
		vec.push_back({ from,to });
		hanoi(num - 1, by, from, to);
	}
}