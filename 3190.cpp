#include <iostream>
#include <queue>
#include <deque>
using namespace std;
typedef pair<int, char> pic;
typedef pair<int, int> pii;

int n, k, l, sec;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit[101][101], ap[101][101];
queue<pic> op;
deque<pii> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0, y, x;i < k;++i) {
		cin >> y >> x;
		ap[y - 1][x - 1] = 1;
	}
	cin >> l;
	for (int i = 0, s;i < l;++i) {
		char p;
		cin >> s >> p;
		op.push(pic(s, p));
	}
	int nxt = 0;
	s.push_back(pii(0, 0));
	visit[0][0] = 1;
	while (1) {
		sec++;
		int ny = s.back().first + dy[nxt], nx = s.back().second + dx[nxt];
		if (visit[ny][nx] || 0 > ny || ny >= n || 0 > nx || nx >= n) {
			cout << sec;
			break;
		}
		visit[ny][nx] = 1;
		s.push_back(pii(ny, nx));
		if (ap[ny][nx]) ap[ny][nx] = 0;
		else {
			visit[s.front().first][s.front().second] = 0;
			s.pop_front();
		}
		if (op.size() && op.front().first == sec) {
			if (op.front().second == 'D') nxt = (nxt + 1) % 4;
			else nxt = (nxt + 3) % 4;
			op.pop();
		}
	}
	return 0;
}