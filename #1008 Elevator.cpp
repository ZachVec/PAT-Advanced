#include <iostream>

int main() {
    size_t n;
    unsigned now = 0, next, ans = 0;
    if(scanf("%zu", &n) == EOF) return 0;
    for(size_t i = 0; i < n && scanf("%u", &next); ++i, now = next) {
        if(next > now) ans += (next - now) * 6;
        else ans += (now - next) * 4;
    }
    ans += 5 * n;
    printf("%u\n", ans);
    return 0;
}
/*
3 2 3 1
41
*/