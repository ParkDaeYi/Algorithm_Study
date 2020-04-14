#include <iostream>
#include <cmath>
using namespace std;
typedef pair<int, int> pii;

struct point {
   int y, x, cnt;
   point(int y = 0, int x = 0, int cnt = 0) :y(y), x(x), cnt(cnt) {}
};
int n, m, ans = 1e9;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
char arr[11][11];
pii red, blue;

int reverse_dir(int cur) {
   if (cur == 0) return 2;
   else if (cur == 2) return 0;
   else if (cur == 1) return 3;
   else if (cur == 3) return 1;
}

void solve(int ry, int rx, int by, int bx, int dir, int cnt) {
   if (cnt > 10 || cnt >= ans) return;
   bool r_flag = 0, b_flag = 0;

   int rny = ry + dy[dir], rnx = rx + dx[dir];
   while (1) {
      if (arr[rny][rnx] == '#') break;
      else if (arr[rny][rnx] == 'O') {
         r_flag = 1;
         break;
      }
      rny += dy[dir];
      rnx += dx[dir];
   }
   rny -= dy[dir], rnx -= dx[dir];

   int bny = by + dy[dir], bnx = bx + dx[dir];
   while (1) {
      if (arr[bny][bnx] == '#') break;
      else if (arr[bny][bnx] == 'O') {
         b_flag = 1;
         break;
      }
      bny += dy[dir];
      bnx += dx[dir];
   }
   bny -= dy[dir], bnx -= dx[dir];

   if (b_flag) return;
   else if (r_flag) {
      ans = ans > cnt ? cnt : ans;
      return;
   }

   if (rny == bny && rnx == bnx) {
      int r_dist = abs(rx - rnx) + abs(ry - rny);
      int b_dist = abs(bx - bnx) + abs(by - bny);
      if (r_dist > b_dist) {
         rny -= dy[dir];
         rnx -= dx[dir];
      }
      else if (r_dist < b_dist) {
         bny -= dy[dir];
         bnx -= dx[dir];
      }
   }

   for (int i = 0; i < 4; ++i) {
      if (i == dir) continue;
      if (i == reverse_dir(dir)) continue;
      solve(rny, rnx, bny, bnx, i, cnt + 1);
   }
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);

   cin >> n >> m;
   for (int i = 0; i < n; ++i) 
      for (int j = 0; j < m; ++j) {
         cin >> arr[i][j];
         if (arr[i][j] == 'R') red = pii(i, j), arr[i][j] = '.';
         else if (arr[i][j] == 'B') blue = pii(i, j), arr[i][j] = '.';
      }

   int ry = red.first, rx = red.second;
   int by = blue.first, bx = blue.second;
   for (int i = 0; i < 4; ++i) solve(ry, rx, by, bx, i, 1);
   if (ans > 10 || ans == 1e9) ans = -1;
   cout << ans;
   return 0;
}