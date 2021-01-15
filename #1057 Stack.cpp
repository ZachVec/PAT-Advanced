#include <iostream>
#include <cstring>
#include <stack>
#define lowbit(x) (x & -x)
using namespace std;
constexpr size_t MAXN = 100001;
unsigned treeLikeArray[MAXN];
size_t binarySearch(size_t l, size_t h, size_t cnt, unsigned (*f)(const size_t)) {
    while(l < h) {
        size_t mid = (l + h) / 2;
        if(f(mid) >= cnt) h = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    auto update = [](const size_t x, unsigned value) {
        for(size_t i = x; i < MAXN; i += lowbit(i)) treeLikeArray[i] += value;
    };
    auto cnts2x = [](const size_t x) {
        unsigned cnt = 0;
        for(size_t i = x; i != 0; i -= lowbit(i)) cnt += treeLikeArray[i];
        return cnt;
    };
    size_t n; char cmd[11];
    stack<unsigned> s;
    if(!scanf("%zu", &n)) return 0;
    for(size_t i = 0, num; i < n && scanf("%s", cmd); ++i) {
        if(strcmp(cmd, "Push") == 0 && scanf("%zu", &num)){
            s.push(num);
            update(num, 1);
        }
        else if(strcmp(cmd, "Pop") == 0 && !s.empty()) {
            printf("%u\n", s.top());
            update(s.top(), -1); s.pop();
        }
        else if(strcmp(cmd, "PeekMedian") == 0 && !s.empty())
            printf("%zu\n", binarySearch(0, MAXN, (s.size() + 1) / 2, cnts2x));
        else printf("Invalid\n");
    }
    return 0;
}