#include <iostream>
#include <vector>
#include <cstdio>
#pragma warning(disable:4996)
#define MIN(a,b) a>b?b:a
#define INTMAX 2147483647
using namespace std;
typedef pair<int, int> pii;

int N, M, result = INTMAX;
vector <pii> house, chicken;
bool visit[14];

inline int _abs(int);
inline int distance(int, int);
void dfs(int, int);

int main() {
	scanf("%d %d\n", &N, &M);

	int tmp;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &tmp);
			if (tmp == 1)
				house.push_back(make_pair(i, j));
			else if (tmp == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	dfs(0, 0);
	printf("%d", result);
	return 0;
}

inline int _abs(int a) {
	if (a < 0) return -a;
	return a;
}
inline int distance(pii p1, pii p2) {
	return _abs(p1.first - p2.first) + _abs(p1.second - p2.second);
}
void dfs(int idx, int selected) {
	if (selected == M) {
		int tmp = 0;
		for (int i = 0; i < house.size(); ++i) {
			int d = INTMAX;
			for (int j = 0; j < chicken.size(); ++j) {
				if (visit[j])
					d = MIN(d, distance(house[i], chicken[j]));
			}
			tmp += d;
		}
		result = MIN(result, tmp);
		return;
	}
	if (idx == chicken.size()) return;
	visit[idx] = true;
	dfs(idx + 1, selected + 1);
	visit[idx] = false;
	dfs(idx + 1, selected);
}