#include <iostream>
using namespace std;

int n, col[15], ans;
// 2차원 배열이 아닌 1차원 배열을 사용
// 퀸은 해당 지점에서 상하좌우 대각으로 이동이 가능하기 때문에
// 1차원 배열에 현재 행에서 열의 위치를 저장하는 방식으로 접근해야 함
// (좌우로 이동이 가능하기 때문에 현재 행에 열의 위치만 알면 됨)

bool whereQueen(int row) {
	for (int i = 0; i < row; ++i) 
		// col[row] == col[i]: 현재 퀸의 위치와 이전(위)의 퀸을 비교(상 체크), 
		// abs(col[row] - col[i]) == row - i: 대각 체크
		if (col[row] == col[i] || abs(col[row] - col[i]) == row - i) return 0;	
	return 1;
}

void queen(int row) {
	if (row == n) ans++;	// 모든 행에 퀸이 조건에 맞게 다 채워져있는 경우
	else {
		for (int i = 0; i < n; ++i) {
			col[row] = i;	// 현재 row(행)에 column(열)의 위치를 저장
			if (whereQueen(row)) queen(row + 1);	// 퀸을 둘 수 있는 곳일 경우
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	queen(0);
	cout << ans;

	return 0;
}