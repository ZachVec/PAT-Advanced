#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    size_t n, amount;
    
    if(scanf("%zu%zu", &n, &amount) != 2) return 0;
    vector<size_t> values(n+1, 0), dp(amount+1, 0);
    vector<vector<bool>> choices(n+1, vector<bool>(amount+1, false));
    
    for(size_t i = 1; i <= n && scanf("%zu", &values[i]); ++i);
    sort(values.begin() + 1, values.end(), greater<size_t>());
    
    for(size_t i = 1; i <= n; ++i) {
        for(size_t j = amount; j >= values[i]; --j) {
            if(dp[j] <= dp[j-values[i]] + values[i]) {
                choices[i][j] = true;
                dp[j] = dp[j-values[i]] + values[i];
            }
        }
    }
    if(dp[amount] != amount) printf("No Solution\n");
    else {
        for(size_t i = n, remain = amount; i > 0 && remain != 0; --i) {
            if(choices[i][remain]) {
                remain -= values[i];
                printf("%zu%c", values[i], " \n"[remain == 0]);
            }
        }
    }
    return 0;
}