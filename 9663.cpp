#include <iostream>
using namespace std;

int N, col[15], cnt;

void Queen(int);
bool WhereQueen(int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	Queen(0);
	cout << cnt;
	return 0;
}

void Queen(int row) {
	if (row == N) ++cnt;
	else {
		for (int i = 0; i < N; ++i) {
			col[row] = i;
			if (WhereQueen(row)) Queen(row + 1);		
		}
	}
}

bool WhereQueen(int row) {
	for (int i = 0; i < row; ++i) {
		if (col[row] == col[i] || abs(col[row] - col[i]) == (row - i))
			return false;
	}
	return true;
}