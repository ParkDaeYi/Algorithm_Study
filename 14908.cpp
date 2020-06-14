#include <iostream>
#include <algorithm>
#define MAX_N 1001
using namespace std;

struct JOB {
	int time, pay, idx;
};

bool cmp(const JOB &a,const JOB& b) {
	int r1 = a.time * b.pay;
	int r2 = b.time * a.pay;
	if (r1 != r2) return r1 < r2;
	return a.idx < b.idx;
}

JOB shoe[MAX_N];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0, t, f; i < n; ++i) {
		cin >> shoe[i].time >> shoe[i].pay;
		shoe[i].idx = i + 1;
	}
	sort(shoe, shoe + n, cmp);
	for (int i = 0; i < n; ++i) cout << shoe[i].idx << " ";

	return 0;
}