#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_COINS = 100;
const int MAX_VALUE = 500;

int n;
int m[MAX_COINS + 1];
bool dp[MAX_COINS * MAX_VALUE / 2 + 1];

int main() {
    cin >> n;
    while (n--) {
        int total = 0;
        memset(dp, 0, sizeof(dp));
        dp[0] = true;
        int numCoins;
        cin >> numCoins;
        for (int i = 1; i <= numCoins; i++) {
            cin >> m[i];
            total += m[i];
            for (int j = total; j >= m[i]; j--) {
                dp[j] |= dp[j - m[i]];
            }
        }
        int half = total / 2;
        while (!dp[half]) {
            half--;
        }
        int diff = total - 2 * half;
        cout << diff << endl;
    }
    return 0;
}
