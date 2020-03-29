#include <iostream>
#include <memory.h>
using namespace std;

class Trie {
private:
	Trie* nxt[10];
	bool term;
public:
	Trie() :term(0) {
		memset(nxt, 0, sizeof(nxt));
	}
	void insert(const char* key) {
		if (*key == '\0') term = 1;
		else {
			int cur = *key - '0';
			if (nxt[cur] == NULL) nxt[cur] = new Trie();
			nxt[cur]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == '\0') return 0;
		if (term) return 1;
		int cur = *key - '0';
		return nxt[cur]->find(key + 1);
	}
};

int t, n;
char number[10001][11];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0;i < n;++i) cin >> number[i];
		bool ret = 0;
		Trie* root = new Trie();
		for (int i = 0;i < n;++i) root->insert(number[i]);
		for (int i = 0;i < n;++i) {
			if (root->find(number[i])) {
				ret = 1; break;
			}
		}
		ret ? cout << "NO\n" : cout << "YES\n";
	}
	return 0;
}