#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#define MAX_N 1001	// 0 <= n <= 1000
#define INF 0x7fffffff	// == INT_MAX
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct Area {
	pii start, end;	// 상가의 위치 저장
	ll cost;	// 상가 이동 시간
};

struct Point {
	pii pos;
	// A*: F = G + H
	ll G = INF, F;
	// G: 시작 노드에서 해당 노드까지의 실제 소요 값
	// H: 휴리스틱 추정 값, 해당 노드에서 최종 목적지까지 도달하는데 소요될 것이라고 추정되는 값
	ll cost[4] = { INF,INF,INF,INF };	// 현재 노드에서 네 방향으로 움직일 수 있음
};

int n, xsize, ysize;
pii src, dest;
pii dir[4] = { {1,0},{-1,0},{0,1},{0,-1} };
Area arr[MAX_N];
vector<ll> xpos, ypos;
unordered_map<int, int> xidx, yidx;
// 최대 나올 수 있는 노드는 MAX_N  * 2
// ==> 출발지점, 도착지점, 상가의 시작과 끝 --> 1 + 1 + 1000 * 2
Point node[MAX_N * 2][MAX_N * 2];
bool visit[MAX_N * 2][MAX_N * 2];

// F = G + H 이므로 F 값을 기준으로 오름차순
struct cmp {
	bool operator() (const Point& p1, const Point& p2) const {
		return p1.F > p2.F;
	}
};

pii operator+(const pii& a, const pii& b) {
	return { a.x + b.x,a.y + b.y };
}

// 휴리스틱 추정 값 연산, 해당 노드에서 최종 목적지까지의 거리를 추정
ll H(pii idx) { return abs(xpos[idx.x] - dest.x) + abs(ypos[idx.y] - dest.y); }

void init(pii now, int d, ll val) {
	pii nxt = now + dir[d];

	// 해당 범위에 속해 있지 않을 경우
	if (nxt.x < 0 || nxt.y < 0 || nxt.x >= xsize || nxt.y >= ysize) {
		node[now.x][now.y].cost[d] = 0;
		return;
	}

	// 현재 노드 저장
	node[now.x][now.y].pos = now;
	// 좌표 압축을 한 상태이므로 해당 거리만큼 value를 곱해준다
	node[now.x][now.y].cost[d] = (abs(xpos[now.x] - xpos[nxt.x]) + abs(ypos[now.y] - ypos[nxt.y])) * val;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> src.x >> src.y >> dest.x >> dest.y;
	xpos.push_back(src.x), xpos.push_back(dest.x);
	ypos.push_back(src.y), ypos.push_back(dest.y);
	cin >> n;
	for (int i = 0, x1, y1, x2, y2, cost; i < n; ++i) {
		cin >> x1 >> y1 >> x2 >> y2 >> cost;
		arr[i] = { {x1,y1},{x2,y2},cost };
		xpos.push_back(x1), xpos.push_back(x2);
		ypos.push_back(y1), ypos.push_back(y2);
	}
	// 중복 값 제거
	sort(xpos.begin(), xpos.end());
	xpos.erase(unique(xpos.begin(), xpos.end()), xpos.end());
	sort(ypos.begin(), ypos.end());
	ypos.erase(unique(ypos.begin(), ypos.end()), ypos.end());

	// map을 사용하여 해당 좌표의 인덱스를 저장한다 (좌표 압축용도)
	for (ll p : xpos) xidx[p] = xsize++;
	for (ll p : ypos) yidx[p] = ysize++;

	// 우선 모든 노드들을 기본 값으로 연결
	for (int xx = 0; xx < xsize; ++xx) for (int yy = 0; yy < ysize; ++yy) for (int i = 0; i < 4; ++i) init({ xx,yy }, i, 10);

	// 상가 지역 연결
	for (int i = 0; i < n; ++i) {
		int start_x = xidx[arr[i].start.x], start_y = yidx[arr[i].start.y];
		int end_x = xidx[arr[i].end.x], end_y = yidx[arr[i].end.y];

		for (int xx = start_x; xx < end_x; ++xx) {
			for (int yy = start_y; yy < end_y; ++yy) {
				// dir[4] = { {1,0},{-1,0},{0,1},{0,-1} }
				// x, y로 저장하였으므로
				// 0: Right, 1: Left, 2: Up, 3: Down 이 됨
				if (xx != start_x) {
					init({ xx,yy }, 2, arr[i].cost);
					init({ xx,yy + 1 }, 3, arr[i].cost);
				}
				if (yy != start_y) {
					init({ xx,yy }, 0, arr[i].cost);
					init({ xx + 1,yy }, 1, arr[i].cost);
				}
				//	ㅇㅁㅁㅁㅇ
				//	ㅇㅁㄱㅁㅇ
				//	ㅇㅁㅁㅁㅇ	ㅇ: 비상가, ㅁ: 상가, ㄱ: 현재 위치라고 가정 (좌표라고 생각하셈)
				//	만약 ㄱ이 상하좌우 중 한 곳에 있다면 갱신할 필요가 없음
				//	==> 상가 지역으로 들어가지 않아도 됨
				//	현재 ㄱ의 위치에서는 상가 지역의 시간으로 갱신해줘야 함
			}
		}
	}

	// A*
	priority_queue<Point, vector<Point>, cmp> pq;
	// 시작 노드의 G 값을 0으로 초기화
	node[xidx[src.x]][yidx[src.y]].G = 0;
	pq.push(node[xidx[src.x]][yidx[src.y]]);
	while (!pq.empty()) {
		Point cur = pq.top(); pq.pop();
		if (visit[cur.pos.x][cur.pos.y]) continue;
		visit[cur.pos.x][cur.pos.y] = 1;

		for (int i = 0; i < 4; ++i) {
			// 사전에 이동불가한 지역의 값은 0으로 갱신 해둠
			if (!cur.cost[i]) continue;
			pii pos = cur.pos + dir[i];
			if (visit[pos.x][pos.y]) continue;
			Point& nxt = node[pos.x][pos.y];
			if (nxt.G > cur.G + cur.cost[i]) {
				// G: 시작 노드에서 해당 노드까지의 실제 소요 값
				// ==> 다익스트라와 비슷하다고 생각하면 됨
				nxt.G = cur.G + cur.cost[i];
				// F = G + H
				nxt.F = nxt.G + H(pos);
				pq.push(nxt);
			}
		}
	}
	cout << node[xidx[dest.x]][yidx[dest.y]].G;
	return 0;
}