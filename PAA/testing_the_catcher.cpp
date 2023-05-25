#include <iostream>
#include <stdio.h>
#include <vector>

int main() {
    int first_missile;
    int test_sequence = 1;

    while(scanf("%d", &first_missile) != EOF && first_missile != -1) {
        std::vector<int> missiles;
        missiles.push_back(first_missile);

        int missile;
        while(scanf("%d", &missile) != EOF && missile != -1) {
            missiles.push_back(missile);
        }

        int n_missiles = missiles.size();
        std::vector<int> lis(n_missiles, 1);

        for(int i = 1; i < n_missiles; i++) {
            for(int j = 0; j < i; j++) {
                if(missiles[i] <= missiles[j] && lis[i] < lis[j] + 1) {
                    lis[i] = lis[j] + 1;
                }
            }
        }

        int max = 0;
        for(int i = 0; i < n_missiles; i++) {
            if(lis[i] > max) {
                max = lis[i];
            }
        }

        printf("Test#%d: \n\tmaximum possible interceptions: %d\n", test_sequence, max);
        test_sequence++;
    }
}