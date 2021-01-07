#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<size_t, unsigned, unsigned> Vertex;  // vertex, dist, cost
typedef vector<vector<Vertex>> Graph;

pair<unsigned, unsigned> dijkstra(const Graph &graph, vector<size_t> &prev, size_t src, size_t dst) {
    vector<bool>     visit(graph.size(), false);
    vector<unsigned> dist(graph.size(), -1);
    vector<unsigned> cost(graph.size(), -1);
    dist[src] = cost[src] = 0;

    for(size_t i = 0; i < graph.size(); ++i) {
        size_t u = -1; unsigned d = -1;
        for(size_t j = 0; j < graph.size(); ++j) {
            if(visit[j] || dist[j] >= d) continue;
            u = j; d = dist[j];
        }

        if(u == size_t(-1)) return { dist[dst], cost[dst] };
        
        visit[u] = true;
        for(const Vertex &nbr : graph[u]) {
            if(visit[get<0>(nbr)] || dist[get<0>(nbr)] < dist[u] + get<1>(nbr)) continue;
            if(dist[u] + get<1>(nbr) < dist[get<0>(nbr)]) {
                dist[get<0>(nbr)] = dist[u] + get<1>(nbr);
                cost[get<0>(nbr)] = cost[u] + get<2>(nbr);
                prev[get<0>(nbr)] = u;
            }
            else if(cost[u] + get<2>(nbr) < cost[get<0>(nbr)]) {
                cost[get<0>(nbr)] = cost[u] + get<2>(nbr);
                prev[get<0>(nbr)] = u;
            }
        }
    }
    return { dist[dst], cost[dst] };
}

int main() {
    size_t n, m, src, dst;
    if(scanf("%zu%zu%zu%zu", &n, &m, &src, &dst) == EOF) return 0;
    Graph graph(n);
    vector<size_t> path;
    vector<size_t> prev(n, -1);
    for(size_t i = 0, u, v; i < m; ++i) {
        unsigned dist, cost;
        if(scanf("%zu%zu%u%u", &u, &v, &dist, &cost) != 4) return 0;
        graph[u].emplace_back(v, dist, cost);
        graph[v].emplace_back(u, dist, cost);
    }
    auto ans = dijkstra(graph, prev, src, dst);
    for(size_t p = dst; p != size_t(-1); p = prev[p]) path.emplace_back(p);
    for(auto it = path.rbegin(); it != path.rend(); ++it) printf("%zu ", *it);
    printf("%u %u\n", ans.first, ans.second);
    return 0;
}