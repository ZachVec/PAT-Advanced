#include <iostream>
#include <cmath>
#include <utility>

int main() {
    unsigned num;
    if(!scanf("%u", &num)) return 0;
    std::pair<unsigned, unsigned> ans = {0, num}; // #factors, begin
    for(unsigned begin = 2, range = unsigned(sqrt(num)), end, n; begin <= range; ++begin) {
        if(num % begin != 0) continue;
        for(end = begin, n = num; n % end == 0; ++end) n /= end;
        if(end - begin> ans.first) ans = {end - begin, begin};
    }
    printf("%u\n%u", ans.first == 0 ? 1 : ans.first, ans.second);
    for(unsigned i = 1; i < ans.first; ++i) printf("*%u", ans.second + i);
    putchar('\n');
    return 0;
}