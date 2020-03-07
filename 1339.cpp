#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define TEN 10
using namespace std;

unsigned int alpha[26], N, sum;
vector <string> vstr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	string tmp;
	for (int n = 0; n < N; ++n) {
		cin >> tmp;
		vstr.push_back(tmp);
	}

	for (int n = 0; n < N; ++n) for (int i = 0; i < vstr[n].size(); ++i) 
        alpha[vstr[n][i] - 'A'] += pow(TEN, vstr[n].size() - 1 - i);
	sort(alpha, alpha + 26, [](const long int& a1, const long int& a2) {
		return a1 > a2;
	});

	for (int i = 9, j = 0; j < 26 || i>0; ++j, --i) {
		if (alpha[j] != 0) sum += alpha[j] * i;
		else break;
	}
	cout << sum;
	return 0;
}