#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
using namespace std;

int n, m, score[9] = { 0,0,0,1,1,2,3,5,11 }, idx = 1, ans, tscore, max_len;
int dy[8] = { 1,1,1,-1,-1,-1,0,0 };
int dx[8] = { 0,1,-1,0,1,-1,1,-1 };
string boggle[4], long_str;
bool visit[4][4];

class Trie {
private:
	Trie* nxt[26];
public:
	int term;
	Trie() :term(0) {
		memset(nxt, 0, sizeof(nxt));
	}
	void insert(const char* key) {
		if (*key == '\0') term = 1;
		else {
			int cur = *key - 'A';
			if (nxt[cur] == NULL) nxt[cur] = new Trie();
			nxt[cur]->insert(key + 1);
		}
	}
	Trie* find(char key) {
		return nxt[key - 'A'];
	}
};
Trie* root = new Trie(), *trie = new Trie();

void dfs(int y, int x, string str) {
	visit[y][x] = 1;
	str += boggle[y][x];
	if (trie->term && trie->term != idx) {	// 중복을 없애기 위해 term 값과 idx를 비교
		++ans;	// 개수
		trie->term = idx;	// 중복 허용 X
		tscore += score[str.size()];	// 점수
		if (max_len < str.size()) {	// 가장 긴 단어
			max_len = str.size();
			long_str = str;	// 가장 긴 단어로 교체
		}
		else if (max_len == str.size()) long_str = min(long_str, str);	// 사이즈가 같을 경우 사전 순 출력
	}
	Trie* copy = trie;
	for (int i = 0;i < 8;++i) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny > 3 || nx > 3) continue;
		if (visit[ny][nx]) continue;
		trie = trie->find(boggle[ny][nx]);	// 현재 트라이에서 boggle[ny][nx]가 연결되어 있는지 확인
		if (trie) dfs(ny, nx, str);
		trie = copy;	// 이전 trie로 변경
	}
	visit[y][x] = 0;	// 백트랙킹
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	char tmp[10];
	while (n--) {
		cin >> tmp;
		root->insert(tmp);
	}
	cin >> m;
	while (m--) {
		++idx;
		ans = max_len = tscore = 0;
		long_str = "";
		for (int i = 0;i < 4;++i) cin >> boggle[i];
		for (int i = 0;i < 4;++i) {
			for (int j = 0;j < 4;++j) {
				trie = root->find(boggle[i][j]);	// 보드의 단어가 단어 사전의 제일 앞 문자에 포함되는지 확인
				if (trie) dfs(i, j, "");
				trie = NULL;	// NULL로 초기화
			}
		}
		cout << tscore << ' ' << long_str << ' ' << ans << '\n';
	}
	return 0;
}