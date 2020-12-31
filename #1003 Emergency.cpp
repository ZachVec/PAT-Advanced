#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

typedef pair<size_t, unsigned> Road;
typedef pair<unsigned, unsigned> Ans;

Ans dijkstra(vector<Road> *g, unsigned *teamNum, size_t n, size_t src, size_t dest) {
    bool     *vis     = new     bool[n]();
    unsigned *dist    = new unsigned[n]();
    unsigned *pathCnt = new unsigned[n]();
    unsigned *teamCnt = new unsigned[n]();
    memset(dist, -1, n * sizeof(unsigned));
    dist[src]    = 0;
    teamCnt[src] = teamNum[src];
    pathCnt[src] = 1;

    for(size_t i = 0; i < n; ++i) {
        unsigned ref = (unsigned)-1;
        size_t u = (size_t)-1;
        for(size_t j = 0; j < n; ++j) {
            if(vis[j] || dist[j] >= ref) continue;
            u = j; ref = dist[j];
        }

        if(u == (size_t)-1) return make_pair(-1, -1);
        vis[u] = true;
        for(const Road &rd : g[u]) {
            if(vis[rd.first] || dist[rd.first] < (ref = dist[u] + rd.second)) continue;
            else if(dist[rd.first] > ref) {
                dist[rd.first]    = ref;
                pathCnt[rd.first] = pathCnt[u];
                teamCnt[rd.first] = teamCnt[u] + teamNum[rd.first];
            }
            else {
                pathCnt[rd.first] += pathCnt[u];
                if(teamCnt[rd.first] < (ref = teamCnt[u] + teamNum[rd.first])) {
                    teamCnt[rd.first] = ref;
                }
            }
        }
    }
    Ans ans = make_pair(pathCnt[dest], teamCnt[dest]);
    delete[] vis;
    delete[] dist;
    delete[] pathCnt;
    delete[] teamCnt;
    return ans;
}

int main() {
    size_t n, m, src, dest;
    unsigned *teams;
    vector<Road> *graph;

    // allocate
    if(scanf("%zu%zu%zu%zu", &n, &m, &src, &dest) == EOF) return 0;
    teams   = new unsigned[n];
    graph   = new vector<Road>[n];

    // read
    for(size_t i = 0; i < n; ++i) scanf("%u", &teams[i]);
    for(size_t i = 0, u, v; i < m; ++i) {
        unsigned d;
        scanf("%zu%zu%u", &u, &v, &d);
        graph[u].emplace_back(v, d);
        graph[v].emplace_back(u, d);
    }

    Ans ans = dijkstra(graph, teams, n, src, dest);
    printf("%u %u\n", ans.first, ans.second);
    
    // deallocate
    delete[] teams;
    delete[] graph;
    return 0;
}

/*
the number of different shortest paths between,
and the maximum amount of rescue teams you can possibly gather.
2 4
*/