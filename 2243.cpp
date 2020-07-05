#include <iostream>
#include <cmath>
using namespace std;
typedef long long int llt;

int n;
llt seg[1 << 21];
const int sz = pow(2, (int)log2(1e6 - 1) + 1);

void find(int node, int rank) {
	if (node >= sz) {
		cout << node - sz + 1 << '\n';
		for (; node > 0; node /= 2) seg[node] -= 1;	// 출력 후 갱신
		return;
	}
	seg[node * 2] >= rank ? find(node * 2, rank) : find(node * 2 + 1, rank - seg[node * 2]);
	// 만약 오른쪽으로 이동해야할 경우 rank - seg[node*2]를 해줌
	// ex. 인덱스 (1에 2개) (2에 1개) (3에 1개) (4에 2개)의 사탕이 있다고 가정
	// 4번째 순위의 사탕은 3임
	//				6
	//			3		3
	//		2		1 1		2	에서 4번째 이므로 root에서 오른쪽으로 가야함
	//	이때 온전히 rank의 값이 4를 유지한다면 원하는 값을 찾을 수 없음
	//	그러므로 오른쪽으로 갈 경우 rank - seg[node*2] 를 해줘야 함
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	int a, b, c;
	while (n--) {
		cin >> a >> b;
		if (a == 1) find(1, b);
		else if (a == 2) {
			cin >> c;
			for (int node = b + sz - 1; node > 0; node /= 2) seg[node] += c;	// 세그먼트 트리 갱신
		}
	}
	return 0;
}