#include <iostream>
#include <vector>
using namespace std;
constexpr unsigned INF = -1U;

int main() {
    size_t n, m, q;
    if(scanf("%zu%zu", &n, &m) != 2) return 0;
    auto all = [](vector<bool>::iterator const &begin, vector<bool>::iterator const &end){
        for(auto it = begin; it != end; ++it) if(!(*it)) return false;
        return true;
    };
    
    unsigned dist;
    vector<vector<unsigned>> graph(n+1, vector<unsigned>(n+1, INF));
    for(size_t i = 0, u, v; i < m && scanf("%zu%zu%u", &u, &v, &dist); ++i) {
        graph[u][v] = graph[v][u] = dist;
    }

    if(!scanf("%zu", &q)) return 0;
    pair<size_t, unsigned> ans(0, -1U);
    for(size_t i = 1, k, front, back; i <= q && scanf("%zu%zu", &k, &front); ++i) {
        dist = 0;
        vector<bool> isVisited(n+1, false);
        for(size_t j = 1, prev = front; j < k && scanf("%zu", &back); ++j, prev = back) {
            if(dist == INF) continue;
            if(graph[prev][back] == INF) dist = INF;
            else dist += graph[prev][back], isVisited[back] = true;
        }
        if(k <= n || front != back || !all(isVisited.begin() + 1, isVisited.end())) {
            if(dist == INF) printf("Path %zu: NA (Not a TS cycle)\n", i);
            else printf("Path %zu: %u (Not a TS cycle)\n", i, dist);
        }
        else {
            printf("Path %zu: %u (TS %s)\n", i, dist, k == n+1 ? "simple cycle" : "cycle");
            if(dist < ans.second) ans = {i, dist};
        }
    }
    printf("Shortest Dist(%zu) = %u\n", ans.first, ans.second);
    return 0;
}