#include <iostream>
#define SIZE 9
using namespace std;

int sudoku[SIZE][SIZE];
bool row[SIZE][SIZE + 1], col[SIZE][SIZE + 1], box[SIZE][SIZE + 1];

bool backtracking(int y, int x) {
	if (y == SIZE) return 1;	// y가 범위를 벗어났을 경우 ==> 스도쿠 완성
	if (!sudoku[y][x]) {
		for (int i = 1; i < SIZE + 1; ++i) {
			if (row[y][i] || col[x][i] || box[y / 3 * 3 + x / 3][i]) continue;	// 이미 값이 있을 경우 continue
			row[y][i] = col[x][i] = box[y / 3 * 3 + x / 3][i] = 1;
			sudoku[y][x] = i;
			int yy = y, xx = x + 1;
			if (xx == SIZE) {	// x가 범위를 벗어났을 경우
				yy++;
				xx = 0;
			}
			if (backtracking(yy, xx)) return 1;
			row[y][i] = col[x][i] = box[y / 3 * 3 + x / 3][i] = 0;
			sudoku[y][x] = 0;
		}
	}
	else {
		if (++x == SIZE) {
			y++;
			x = 0;
		}
		if (backtracking(y, x)) return 1;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < SIZE; ++i) 
		for (int j = 0; j < SIZE; ++j) {
			cin >> sudoku[i][j];
			if (sudoku[i][j]) row[i][sudoku[i][j]] = col[j][sudoku[i][j]] = box[i / 3 * 3 + j / 3][sudoku[i][j]] = 1;
			// 행, 열, 박스(3 * 3) 단위에 있는 숫자 체크
		}
	
	backtracking(0, 0);
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			cout << sudoku[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}