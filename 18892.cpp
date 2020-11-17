#include <iostream>
#include <vector>
#define MAX 500
using namespace std;
typedef long long ll;

struct node {
	int len;
	ll cnt;
}bit[MAX + 1], lis[MAX];
int N, K, a[MAX];

node merge(node& l, node& r) {
	if (l.len ^ r.len) return l.len > r.len ? l : r;
	return { l.len,l.cnt + r.cnt };	// l과 r의 길이가 같다면 갯수를 합침
}

void update(int i, node& n) {
	++n.len;	// lis의 node의 길이 추가
	if (!n.cnt) ++n.cnt;	// lis의 node의 cnt가 없다면 1로 갱신
	for (;i <= N;i += i & -i) bit[i] = merge(bit[i], n);	// bit 갱신
}

node query(int i) {
	node ret = { 0,0 };
	for (;i;i -= i & -i) ret = merge(ret, bit[i]);	// i에서 구할 수 있는 lis의 길이와 개수
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0;i < N;++i) cin >> a[i];
	// ex. 1 2 3 4 5 6
	// i	N - a[i]	N - a[i] + 1
	// 5	0|			1| 1 2 4
	// 4	1| 1		2| 2 4
	// 3	2| 2		3| 3 4
	// 2	3| 3 2		4| 4
	// 1	4| 4		5| 5 6
	// 0	5| 5 4		6| 6
	// N - a[i] + 1 전에, 즉 N - a[i]에서 query를 통해 현재 node를 구하고
	// N - a[i] + 1 에서 해당 값을 업데이트
	for (int i = N - 1;~i;--i) update(N - a[i] + 1, lis[i] = query(N - a[i]));
	node tt = query(N);	// 최종 길이와 개수
	if (tt.cnt < K) { cout << -1; return 0; }
	--K;
	vector<vector<int>> v(tt.len + 1);
	// v의 lis[i].len에 idx를 저장
	for (int i = 0;i < N;++i) v[lis[i].len].emplace_back(i);
	int prv = -1;
	for (int i = tt.len;i;--i) {
		while (a[v[i].back()] < prv) v[i].pop_back();
		while (lis[v[i].back()].cnt <= K) {
			K -= lis[v[i].back()].cnt;
			v[i].pop_back();
		}
		cout << (prv = a[v[i].back()]) << ' ';
	}
	return 0;
}