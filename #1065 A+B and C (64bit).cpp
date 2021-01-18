#include <iostream>

int main() {
    size_t n;
    long long a, b, c;
    if(!scanf("%zu", &n)) return 0;
    for(size_t i = 1; i <= n && scanf("%lld%lld%lld", &a, &b, &c); ++i) {
        bool flag;
        long long sum = a + b;
        if((a >= 0) != (b >= 0)) flag = sum > c;
        else flag = (sum >= 0) != (a >= 0) ? (a >= 0) : (sum > c);
        printf("Case #%zu: %s\n", i, flag ? "true" : "false");
    }
    return 0;
}