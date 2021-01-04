#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
set<size_t> ans;
vector<size_t> tempAns, graph[10001];

void DFS(size_t src, bool *vis, unsigned &maxDepth, unsigned depth) {
    vis[src] = true;
    if(depth > maxDepth) {
        maxDepth = depth;
        tempAns.clear();
        tempAns.push_back(src);
    }
    else if(depth == maxDepth) {
        tempAns.push_back(src);
    }
    for(size_t nbr : graph[src]) {
        if(vis[nbr]) continue;
        DFS(nbr, vis, maxDepth, depth + 1);
    }
}

int main() {
    size_t n;
    bool *vis;
    unsigned cnt = 0, maxDepth = 0;

    if(scanf("%zu", &n) == EOF) return 0;
    vis = new bool[n+1]();
    for(size_t i = 1, u, v; i < n && scanf("%zu%zu", &u, &v); ++i) {
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for(size_t src = 1; src <= n; ++src) {
        if(vis[src]) continue;
        ++cnt;
        DFS(src, vis, maxDepth, 0);
    }

    if(cnt == 1) {
        fill(vis, vis + n + 1, false);
        for(size_t i : tempAns) ans.insert(i);
        DFS(tempAns.front(), vis, maxDepth, 0);
        for(size_t i : tempAns) ans.insert(i);
        for(const size_t i : ans) printf("%zu\n", i);
    }
    else printf("Error: %u components\n", cnt);

    delete[] vis;
    return 0;
}
/*
5
1 2
1 3
1 4
2 5

3
4
5

5
1 3
1 4
2 5
3 4

Error: 2 components
*/