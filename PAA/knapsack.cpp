#include <iostream>
#include <bits/stdc++.h>

int main() {
    int w, n;
    std::cin >> w >> n;

    int dp[n];
    for (int i = 0; i < n; i++) {
        std::cin >> dp[i];
    }

    // sort dp
    std::sort(dp, dp + n, std::greater<int>());

    int ans = 0;
    while(n--) {
        ans++;
    }

    std::cout << ans << std::endl;
}