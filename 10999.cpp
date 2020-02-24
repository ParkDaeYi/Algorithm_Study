#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

llt seg[1 << 21], lazy[1 << 21];
int n, m, k;

llt sum(int, int, int, int, int);
void update_range(int, int, int, int, int, llt);
void update_lazy(int, int, int);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	const int sz = pow(2, (int)log2(n - 1) + 1);
	for (int i = 0; i < n; ++i) cin >> seg[sz + i];
	for (int i = sz - 1; i > 0; --i) seg[i] = seg[i * 2] + seg[i * 2 + 1];
	for (int i = 0; i < m + k; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			update_range(1, 1, sz, b, c, d);
		}
		else cout << sum(1, 1, sz, b, c) << '\n';
	}
	return 0;
}

void update_lazy(int node, int start, int end) {
	//lazy가 0이면 return
	if (!lazy[node]) return;

	// 자식 노드가 있는 수 만큼 lazy 값에 곱하여 더함
	// 자식에게 lazy를 분배하니 자식이 return으로 더해주지 못한 값을 직접 더함
	seg[node] += (end - start + 1) * lazy[node];
	
	//leaf가 아니면
	//자식에게 lazy를 물려줌
	if (start != end) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}

	//물려준 후 lazy는 초기화
	lazy[node] = 0;
	return;
}

void update_range(int node, int start, int end, int left, int right, llt val) {
	/*
	* 1. lazy가 존재하면 업데이트 해줌(seg[node] 변화)
	* 2. val을 더해줌 (자식 수가 있는 만큼)
	* 2에서 자식 수만큼 더해주는 이유는 자식들은 아직 lazy가 업데이트 되지 않았기 때문
	*/
	//현재 노드에 lazy가 있는지 확인 후
	// lazy가 있다면 node를 업데이트
	update_lazy(node, start, end);

	//하나도 속하지 않는다면 return
	if (left > end || right < start) return;
	
	//원하는 구간 내에 있는 노드에 왔을 경우
	if (left <= start && end <= right) {
		// 자식 노드가 있는 수 만큼 val을 곱해서 더해줌
		// 자식이 return 으로 더해주는 형태가 아니니 직접 더한다.
		seg[node] += (end - start + 1) * val;
		if (start != end) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(node * 2, start, mid, left, right, val);
	update_range(node * 2 + 1, mid + 1, end, left, right, val);

	// 구간이 걸쳐서 속해 있다면 자식 노드를 이용하여 부모 노드를 업데이트
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

llt sum(int node, int start, int end, int left, int right) {
	//update 이후 남은 lazy를 해당하는 구간을 sum 할 때 업데이트 해줘야함
	update_lazy(node, start, end);
	if (left <= start && end <= right) return seg[node];
	if (end < left || right < start) return 0;
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}