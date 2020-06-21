// 카탈란 수
#include <iostream>
#define MOD 987654321
using namespace std;
typedef long long int llt;

llt d[5001] = { 1 };
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    n /= 2;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < i; j++) {
            d[i] += (d[j] % MOD) * (d[i - 1 - j] % MOD) % MOD;
            d[i] %= MOD;
        }
        d[i] %= MOD;
    }

    cout << d[n];
    return 0;
}