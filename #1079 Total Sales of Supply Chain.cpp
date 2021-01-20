#include <iostream>
#include <queue>
using namespace std;
double BFS(const vector<vector<size_t>> &graph, const vector<unsigned> &sales, double price, double rate) {
    double ans = 0;
    vector<bool> visit(graph.size(), false);
    queue<size_t> q; q.push(0); visit[0] = true;
    for(double multiplier = price; !q.empty(); multiplier *= (1+rate)) {
        for(size_t sz = q.size(); sz--; q.pop()){
            if(graph[q.front()].empty()) ans += sales[q.front()] * multiplier;
            for(const size_t &id : graph[q.front()]) {
                if(visit[id]) continue;
                visit[id] = true; q.push(id);
            }
        }
    }
    return ans;
}

int main() {
    size_t n;
    double price, rate;
    if(scanf("%zu%lf%lf", &n, &price, &rate) !=3) return 0;
    vector<unsigned> sales(n);
    vector<vector<size_t>> graph(n);
    for(size_t i = 0, k; i < n && scanf("%zu", &k); ++i) {
        if(k == 0 && !scanf("%u", &sales[i])) return 0;
        for(size_t j = 0, id; j < k && scanf("%zu", &id); ++j) 
            graph[i].emplace_back(id);
    }
    printf("%.1f\n", BFS(graph, sales, price, rate/100));
    return 0;
}