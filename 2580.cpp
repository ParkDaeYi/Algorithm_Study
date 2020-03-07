#include <iostream>
#define S 9
using namespace std;

bool rowCheck[S][S + 1], colCheck[S][S + 1], boxCheck[S][S + 1];
int sudoku[S][S];

bool backtrack(int, int);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> sudoku[i][j];
			if (sudoku[i][j] != 0) {
				rowCheck[i][sudoku[i][j]] = true;
				colCheck[j][sudoku[i][j]] = true;
				boxCheck[i / 3 * 3 + j / 3][sudoku[i][j]] = true;
			}
		}
	}
	backtrack(0, 0);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

bool backtrack(int y, int x) {
	if (y == S) return true;
	if (sudoku[y][x] == 0) {
		for (int i = 1; i < 10; ++i) {
			if (rowCheck[y][i] || colCheck[x][i] || boxCheck[y / 3 * 3 + x / 3][i]) continue;
			rowCheck[y][i] = true;
			colCheck[x][i] = true;
			boxCheck[y / 3 * 3 + x / 3][i] = true;
			sudoku[y][x] = i;
			int yy = y;
			int xx = x + 1;
			if (xx == S) {
				xx = 0;
				yy++;
			}
			if (backtrack(yy, xx)) return true;
			rowCheck[y][i] = false;
			colCheck[x][i] = false;
			boxCheck[y / 3 * 3 + x / 3][i] = false;
			sudoku[y][x] = 0;
		}
	}
	else {
		int yy = y;
		int xx = x + 1;
		if (xx == S) {
			xx = 0;
			yy++;
		}
		if (backtrack(yy, xx)) return true;
	}
	return false;
}