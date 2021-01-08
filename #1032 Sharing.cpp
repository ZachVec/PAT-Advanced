#include <iostream>
#include <utility>
using namespace std;
typedef pair<size_t, bool> Node;
Node nodes[100000];

int main() {
    size_t addr1, addr2, n, ans;
    if(scanf("%zu%zu%zu", &addr1, &addr2, &n) == EOF) return 0;
    for(size_t i = 0, u, v; i < n && scanf("%zu %*c %zu", &u, &v); ++i) 
        nodes[u] = {v, false};
    for(ans = addr1; ans != size_t(-1); ans = nodes[ans].first) 
        nodes[ans].second = true;
    for(ans = addr2; ans != size_t(-1); ans = nodes[ans].first) 
        if(nodes[ans].second) break;
    if(ans == size_t(-1)) printf("-1\n");
    else printf("%05zu", ans);
    return 0;
}