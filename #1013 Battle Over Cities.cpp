#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;
constexpr size_t MAXN = 1001;
bool vis[MAXN];
vector<size_t> graph[MAXN];

void DFS(size_t src, size_t nowCity) {
    if(src == nowCity) return;
    vis[src] = true;
    for(auto city : graph[src]) {
        if(vis[city] || city == nowCity) continue;
        DFS(city, nowCity);
    }
}

int main() {
    size_t n, m, k;
    if(scanf("%zu%zu%zu", &n, &m, &k) == EOF) return 0;
    for(size_t i = 0, u, v; i < m && scanf("%zu%zu", &u, &v); ++i) {
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    for(size_t i = 0, nowCity; i < k && scanf("%zu", &nowCity); ++i) {
        unsigned cnt = 0;
        memset(vis, 0, MAXN * sizeof(bool));
        for(size_t j = 1; j <= n; ++j) {
            if(vis[j] || j == nowCity) continue;
            ++cnt;
            DFS(j, nowCity);
        }
        printf("%u\n", cnt-1);
    }
    return 0;
}

/*
3 2 3
1 2
1 3
1 2 3

1
0
0
*/