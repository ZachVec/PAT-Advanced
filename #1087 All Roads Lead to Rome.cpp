#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef string City;
typedef size_t Vertex;
typedef unsigned Cost, Happiness;
typedef pair<Vertex, Cost> Road;
typedef vector<vector<Road>> Graph;
typedef vector<vector<Vertex>> UnweightedGraph;

unsigned cnt = 0;
Happiness hpAns = 0;
vector<Vertex> pathTemp, pathAns;
unordered_map<City, Vertex> name2vertex;

void DFS(const UnweightedGraph &prev, const vector<Happiness> &hp, Vertex root) {
    pathTemp.emplace_back(root);
    if(root == 0) { // if root is src
        Happiness tempHappiness = 0; ++cnt;
        for(const Vertex &v : pathTemp) tempHappiness += hp[v];
        if(tempHappiness > hpAns) {
            hpAns = tempHappiness;
            pathAns = pathTemp;
        }
        else if(tempHappiness == hpAns && pathTemp.size() < pathAns.size()) 
            pathAns = pathTemp;
    }
    else for(const Vertex &v : prev[root]) DFS(prev, hp, v);
    pathTemp.pop_back();
}

Cost dijkstra(const Graph &graph, UnweightedGraph &prev, const Vertex &src, const Vertex &dest) {
    vector<bool> visit(graph.size(), false);
    vector<Cost> costs(graph.size(), -1);
    costs[src] = 0;
    
    for(size_t i = 0; i < graph.size(); ++i) {
        Vertex u = -1; Cost cost = -1;
        for(size_t j = 0; j < costs.size(); ++j) {
            if(visit[j] || costs[j] > cost) continue;
            u = j; cost = costs[j];
        }

        if(u == Vertex(-1)) return costs[dest];
        visit[u] = true;
        for(const Road &rd : graph[u]) {
            if(visit[rd.first] || cost + rd.second > costs[rd.first]) continue;
            if(cost + rd.second < costs[rd.first]) {
                costs[rd.first] = cost + rd.second;
                prev[rd.first].clear(); 
                prev[rd.first].emplace_back(u);
            }
            else prev[rd.first].emplace_back(u);
        }
    }
    return costs[dest];
}

int main() {
    size_t n, k;
    City srcName;
    cin >> n >> k >> srcName;
    
    vector<City> vertex2name;
    vector<Happiness> happiness;
    name2vertex[srcName] = 0;
    vertex2name.emplace_back(srcName);
    happiness.emplace_back(0);

    Graph graph(n); City name1; Happiness hp; 
    for(size_t i = 1; i < n && cin >> name1 >> hp; ++i) {
        name2vertex[name1] = i; 
        vertex2name.emplace_back(name1);
        happiness.emplace_back(hp);
    }

    UnweightedGraph prev(n); City name2; Cost cost;
    for(size_t i = 0, u, v; i < k && cin >> name1 >> name2 >> cost; ++i) {
        u = name2vertex[name1]; v = name2vertex[name2];
        graph[u].emplace_back(v, cost);
        graph[v].emplace_back(u, cost);
    }

    cost = dijkstra(graph, prev, 0, name2vertex["ROM"]);
    DFS(prev, happiness, name2vertex["ROM"]);
    printf("%u %u %u %u\n%s", cnt, cost, hpAns, hpAns / unsigned(pathAns.size()-1), srcName.c_str());
    for(auto it = pathAns.rbegin() + 1; it != pathAns.rend(); ++it) printf("->%s", vertex2name[*it].c_str());
    putchar('\n');
    return 0;
}