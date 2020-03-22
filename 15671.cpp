#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
typedef pair<int, int> pii;

int n, arr[6][6], dx[8] = { 1,-1,0,0,1,1,-1,-1 }, dy[8] = { 0,0,1,-1,1,-1,1,-1 };

void simul(int y, int x, int v) {
	arr[y][x] = v;
	for (int i = 0; i < 8; ++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= 6 || nx >= 6 || !arr[ny][nx]) continue;
		if (arr[ny][nx] != v) {
			vector<pii> vec;
			vec.push_back(pii(ny, nx));
			int yy = ny + dy[i], xx = nx + dx[i];
			while (yy >= 0 && xx >= 0 && yy < 6 && xx < 6) {
				if (!arr[yy][xx]) break;
				if (arr[yy][xx] == v) {
					for (pii p : vec) arr[p.first][p.second] = v;
					break;
				}
				vec.push_back(pii(yy, xx));
				yy += dy[i];
				xx += dx[i];
			}
		}
	}
	return;
}

int main() {

	scanf("%d\n", &n);
	arr[2][2] = arr[3][3] = 1;
	arr[2][3] = arr[3][2] = 2;
	for (int i = 0, y, x; i < n; ++i) {
		scanf("%d %d", &y, &x);
		simul(y - 1, x - 1, (i + 1) % 2 + 1);
	}
	int wcnt = 0, bcnt = 0;
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 6; ++j) {
			if (!arr[i][j]) printf(".");
			else if (arr[i][j] == 1) {
				printf("W");
				wcnt++;
			}
			else {
				printf("B");
				bcnt++;
			}
		}
		printf("\n");
	}
	if (wcnt > bcnt) printf("White");
	else printf("Black");
	return 0;
}