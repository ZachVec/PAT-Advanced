#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n, ans = -1;
    if(!scanf("%zu", &n)) return 0;
    
    vector<size_t> numberOf(10001, 0);
    for(size_t i = 0, length; i < n && scanf("%zu", &length); ++i) {
        ++numberOf[length];
        ans = min(length, ans);
    }
    for(size_t len = ans; len < numberOf.size(); ++len) {
        for(size_t i = 0; i < numberOf[len]; ++i) ans = (ans + len) / 2;
    }
    printf("%zu\n", ans);
    return 0;
}