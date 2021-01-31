#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<size_t, unsigned, unsigned> Node;
typedef pair<unsigned, vector<size_t>> Ans;

Ans dijkstra(const vector<vector<Node>> &graph, const size_t &src, const size_t &dest) {
    typedef tuple<unsigned, unsigned, size_t, size_t> NodeWithPrev; //w1, w2, prev, vertex
    vector<bool> visit(graph.size(), false);
    vector<size_t> path, precede(graph.size(), -1);

    unsigned w1, w2; size_t vertex, prev; 
    priority_queue<NodeWithPrev, vector<NodeWithPrev>, greater<NodeWithPrev>> q;
    for(q.emplace(0, 0, -1, src); !q.empty(); q.pop()) {
        tie(w1, w2, prev, vertex) = q.top();
        if(visit[vertex]) continue;
        visit[vertex] = true;
        precede[vertex] = prev;
        if(vertex == dest) break;
        for(const Node &node : graph[vertex]) {
            if(!visit[get<0>(node)]) q.emplace(w1 + get<1>(node), w2 + get<2>(node), vertex, get<0>(node));
        }
    }
    for(size_t city = dest; city != size_t(-1); city = precede[city]) path.emplace_back(city);
    return {w1, path};
}

int main() {
    size_t n, k, src, dest;
    unsigned length, time;

    if(scanf("%zu%zu", &n, &k) != 2) return 0;
    vector<vector<Node>> distGraph(n), timeGraph(n);
    for(size_t i = 0, u, v, flag; i < k && scanf("%zu%zu%zu%u%u", &u, &v, &flag, &length, &time); ++i){
        distGraph[u].emplace_back(v, length, time);
        timeGraph[u].emplace_back(v, time, 1);
        if(flag) continue;
        distGraph[v].emplace_back(u, length, time);
        timeGraph[v].emplace_back(u, time, 1);
    }
    if(scanf("%zu%zu", &src, &dest) != 2) return 0;

    Ans distAns = dijkstra(distGraph, src, dest);
    Ans timeAns = dijkstra(timeGraph, src, dest);
    if(distAns.second == timeAns.second) {
        printf("Distance = %u; Time = %u:", distAns.first, timeAns.first);
        for(auto it = distAns.second.rbegin(); it != distAns.second.rend(); ++it) 
            printf(" %zu%s", *it, *it == distAns.second.front() ? "\n" : " ->");
    }
    else {
        printf("Distance = %u:", distAns.first);
        for(auto it = distAns.second.rbegin(); it != distAns.second.rend(); ++it) 
            printf(" %zu%s", *it, *it == distAns.second.front() ? "\n" : " ->");
        printf("Time = %u:", timeAns.first);
        for(auto it = timeAns.second.rbegin(); it != timeAns.second.rend(); ++it) 
            printf(" %zu%s", *it, *it == timeAns.second.front() ? "\n" : " ->");
    }
    return 0;
}