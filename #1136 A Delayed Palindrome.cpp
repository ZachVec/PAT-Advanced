#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<unsigned short> BIGINT;
constexpr size_t MAX_ITERATION = 10;

bool isPalindrome(const BIGINT &digits){
    for(size_t i = 0; i < digits.size() / 2; ++i) {
        if(digits[i] == digits[digits.size()-1-i]) continue;
        return false;
    }
    return true;
}

BIGINT addRev(const BIGINT &a){
    BIGINT ret;
    unsigned short carry = 0;
    for(size_t i = 0; i < a.size(); ++i) {
        carry += a[i] + a[a.size() - i - 1];
        ret.emplace_back(carry % 10);
        carry /= 10;
    }
    if(carry) ret.emplace_back(carry);
    return ret;
}

int main() {
    BIGINT ori;
    for(char ch; scanf("%c", &ch) && isdigit(ch); ori.emplace_back(ch-'0'));
    std::reverse(ori.begin(), ori.end());
    for(size_t i = 0; i < MAX_ITERATION && !isPalindrome(ori); ++i) {
        for(auto it = ori.rbegin(); it != ori.rend(); ++it) printf("%hu", *it);
        printf(" + ");
        for(auto it = ori.begin();  it != ori.end();  ++it) printf("%hu", *it);
        printf(" = "); ori = addRev(ori);
        for(auto it = ori.rbegin(); it != ori.rend(); ++it) printf("%hu", *it);
        putchar('\n');
    }
    if(isPalindrome(ori)) {
        for(auto it = ori.rbegin(); it != ori.rend(); ++it) printf("%hu", *it);
        printf(" is a palindromic number.\n");
    }
    else printf("Not found in %zu iterations.\n", MAX_ITERATION);
    return 0;
}