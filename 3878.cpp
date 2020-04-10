#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 101
using namespace std;
typedef long long int llt;

class point {
public:
   int x, y, dx, dy;
   point(int x = 0, int y = 0) :x(x), y(y), dx(0), dy(0) {}
   bool operator<(const point& p) const {
      if (1LL * dy * p.dx != 1LL * dx * p.dy) return 1LL * dy * p.dx < 1LL * dx * p.dy;
      return y == p.y ? x < p.x : y < p.y;
   }
};
int t, n, m;
vector<point> a, b;

int ccw(point a, point b, point c) {
   llt tmp = a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
   return tmp == 0 ? 0 : tmp > 0 ? 1 : -1;
}

void init(int sz, vector<point>& v) {
   v.clear();
   point pos[MAX_N];
   for (int i = 0; i < sz; ++i) cin >> pos[i].x >> pos[i].y;
   sort(pos, pos + sz);
   for (int i = 1; i < sz; ++i) pos[i].dx = pos[i].x - pos[0].x, pos[i].dy = pos[i].y - pos[0].y;
   sort(pos + 1, pos + sz);
   for (int i = 0; i < sz; ++i) {
      while (v.size() > 1 && ccw(v[v.size() - 2], v.back(), pos[i]) <= 0) v.pop_back();
      v.push_back(pos[i]);
   }
}

//a와 b의 정점 중 다각형에 포함되는 경우를 판별
bool isInside(point q, vector<point>& p) {
   //cross는 점 q와 다각형의 오른쪽 반직선과의 교점 개수
   int sz = p.size(), cross = 0;
   for (int i = 0; i < sz; ++i) {
      int j = (i + 1) % sz;
      //점 q가 선분 (p[i], p[j])의 y좌표 사이에 있을 경우
      if (p[i].y > q.y != p[j].y > q.y) {
         double atX = (double)((p[j].x - p[i].x) * (q.y - p[i].y)) / (p[j].y - p[i].y) + p[i].x;
         //atX가 q.x보다 클 경우 cross 증가
         //atx는 q.x 와 동일 선상에 존재하는 p[i], p[j] 선분 사이의 한 점
         if (q.x < atX) cross++;
      }
   }
   return cross % 2;
}

//ab 와 cd가 겹치지 않는 경우 true를 반환
bool disjoint(int a, int b, int c, int d) {
   if (a > b) swap(a, b);
   if (c > d) swap(c, d);
   return b < c || d < a;
}

//두 선분이 서로 교차하는지 여부를 반환
bool sementIntersects(point a, point b, point c, point d) {
   //세 점 a, b, c의 회전 방향 검사에서
   //선분이 교차한다면 음수를 반환
   int ab = ccw(a, b, c) * ccw(a, b, d);
   int cd = ccw(c, d, a) * ccw(c, d, b);
   //두 선분이 일직선에 있는 경우
   if (!ab && !cd) return !(disjoint(a.x, b.x, c.x, d.x) || disjoint(a.y, b.y, c.y, d.y));   
   //선분의 끝점이 교차점이 되는 경우를 포함
   return ab <= 0 && cd <= 0;
}

bool solve() {
   //얘는 왜 해주는지 모르겠어서 일단 주석처리 해둠
   //if (isInside(a[0], b) || isInside(b[0], a)) return 1;
   for (point p : a) if (isInside(p, b)) return 1;
   for (point p : b) if (isInside(p, a)) return 1;
   n = a.size(), m = b.size();
   for (int i = 0; i < n; ++i) 
      for (int j = 0; j < m; ++j) {
         if (sementIntersects(a[i], a[(i + 1) % n], b[j], b[(j + 1) % m])) return 1;
      }
   return 0;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   cin >> t;
   while (t--) {
      cin >> n >> m;
      init(n, a); init(m, b);
      cout << (solve() ? "NO\n" : "YES\n");
   }
   return 0;
}