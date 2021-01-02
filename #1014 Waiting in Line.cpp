#include <iostream>
#include <queue>
using namespace std;
constexpr unsigned MAXN = 20;
constexpr unsigned MAXK = 2001; 
typedef struct Window{
    unsigned popTime, endTime;
    queue<size_t> customer;
    Window() : popTime(8*60), endTime(8 * 60) {}
} Win;
Window windows[MAXN];
unsigned ans[MAXK], cost[MAXK];

int main() {
    size_t n, m, k, q;
    if(scanf("%zu%zu%zu%zu", &n, &m, &k, &q) == EOF) return 0;
    for(size_t i = 1; i <= k; ++i) scanf("%u", &cost[i]);
    for(size_t i = 1; i <= k; ++i) {
        if(i <= n * m) {
            Window &w = windows[(i-1) % n];
            if(i <= n) w.popTime += cost[i];
            ans[i] = w.endTime = w.endTime + cost[i];
            w.customer.push(i);
        }
        else {
            size_t u = -1;
            unsigned minPopTime = -1;
            for(size_t j = 0; j < n; ++j) {
                if(windows[j].popTime < minPopTime) 
                    u = j; minPopTime = windows[j].popTime;
            }
            Window &w = windows[u];
            w.customer.pop();
            w.popTime += cost[w.customer.front()];
            ans[i] = w.endTime = w.endTime + cost[i];
            w.customer.push(i);
        }
    }
    for(size_t i = 0, query; i < q && scanf("%zu", &query); ++i) 
        if(ans[query] - cost[query] >= 1020) printf("Sorry\n");
        else printf("%02u:%02u\n", ans[query] / 60, ans[query] % 60);
    return 0;
}
/*
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7

20 10 1000 1000

08:07
08:06
08:10
17:00
Sorry
*/