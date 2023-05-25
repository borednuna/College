#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 30005;

int main() {
    int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    int n = sizeof(coins) / sizeof(int);
    long long dp[MAXN];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coins[i]; j < MAXN; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }
    double amount;
    while (scanf("%lf", &amount) == 1 && amount > 0) {
        int x = (int)(amount * 100 + 0.5);
        printf("%6.2f%17lld\n", amount, dp[x]);
    }
    return 0;
}
