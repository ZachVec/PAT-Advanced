#include <iostream>
#include <vector>
using namespace std;
size_t DFSTrav(const vector<vector<size_t>> &graph, const size_t &src){
    vector<bool> visit(graph.size(), false);
    auto DFS = [&graph, &visit](const size_t &src, const auto &DFS_ref) -> size_t {
        if(visit[src]) return 0;
        size_t cnt = 1; visit[src] = true;
        for(const size_t &nbr : graph[src]) cnt += DFS_ref(nbr, DFS_ref);
        return cnt;
    };
    return DFS(1, DFS);
}


int main() {
    size_t n, m, cnt, oddDegreeCnt = 0;
    if(scanf("%zu%zu", &n, &m) != 2) return 0;

    vector<size_t> degree(n+1);
    vector<vector<size_t>> graph(n+1);
    for(size_t i = 0, u, v; i < m && scanf("%zu%zu", &u, &v); ++i) {
        graph[u].emplace_back(v); graph[v].emplace_back(u);
        ++degree[u]; ++degree[v];
    }
    cnt = DFSTrav(graph, 1);
    for(size_t i = 1; i <= n; ++i) {
        printf("%zu%c", degree[i], " \n"[i==n]);
        if(degree[i] % 2 == 1) ++oddDegreeCnt;
    }
    if(oddDegreeCnt == 0 && cnt == n) printf("Eulerian\n");
    else if(oddDegreeCnt == 2 && cnt == n) printf("Semi-Eulerian\n");
    else printf("Non-Eulerian\n");
    return 0;
}