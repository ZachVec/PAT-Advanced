#include <iostream>
constexpr size_t MAXN = 1000;
bool dp[MAXN][MAXN];

int main() {
    size_t ans = 1;
    std::string str;
    std::getline(std::cin, str);
    for(size_t i = 0; i < str.length(); ++i) dp[i][i] = true;
    for(size_t i = 0; i < str.length()-1; ++i) {
        if((dp[i][i+1] = str[i] == str[i+1]))
            ans = 2;
    }
    for(size_t len = 3; len <= str.length(); ++len) {
        for(size_t i = 0, j = len - 1; j < str.length(); ++i, ++j) {
            if((dp[i][j] = dp[i+1][j-1] && str[i] == str[j]))
                ans = len;
        }
    }
    printf("%zu\n", ans);
    return 0;
}