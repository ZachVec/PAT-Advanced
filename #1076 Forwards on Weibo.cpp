#include <iostream>
#include <queue>
using namespace std;
unsigned BFS(const vector<vector<size_t>> &graph, size_t maxLevel, size_t src) {
    unsigned cnt = 0;
    vector<bool> visit(graph.size(), false);
    queue<size_t> q; q.push(src);
    visit[src] = true;
    for(size_t level = 0; level < maxLevel; ++level) {
        for(size_t i = 0, sz = q.size(); i < sz; ++i, q.pop()) {
            for(const size_t &follower : graph[q.front()]) {
                if(visit[follower]) continue;
                visit[follower] = true;
                q.push(follower); ++cnt;
            }
        }
    }
    return cnt;
}

int main() {
    size_t n, maxLevel, k;
    if(scanf("%zu%zu", &n, &maxLevel) != 2) return 0;
    vector<vector<size_t>> graph(n);
    for(size_t id = 0, m; id < n && scanf("%zu", &m); ++id) 
        for(size_t i = 0, followee; i < m && scanf("%zu", &followee); ++i) 
            graph[followee-1].emplace_back(id);

    if(!scanf("%zu", &k)) return 0;
    for(size_t i = 0, src; i < k && scanf("%zu", &src); ++i) {
        printf("%u\n", BFS(graph, maxLevel, src - 1));
    }
    return 0;
}