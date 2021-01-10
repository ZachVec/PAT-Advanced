#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n, k, temp, maximum = 0;

    if(scanf("%zu%zu", &n, &k) != 2) return 0;
    vector<size_t> pri(n + 1, 0), seq;
    for(size_t i = 1; i <= k && scanf("%zu", &temp); ++i) 
        pri[temp] = i;
    if(scanf("%zu", &k) != 1) return 0;
    for(size_t i = 0; i < k && scanf("%zu", &temp); i++) {
        if(pri[temp]) seq.emplace_back(pri[temp]);
    }
    
    vector<size_t> dp(seq.size(), 1);
    for(size_t i = 0; i < seq.size(); ++i) {
        for(size_t j = 0; j < i; ++j) {
            if(seq[j] <= seq[i] && dp[i] <= dp[j])
                dp[i] = dp[j] + 1;
        }
        if(maximum < dp[i]) maximum = dp[i];
    }
    printf("%zu\n", maximum);
    return 0;
}