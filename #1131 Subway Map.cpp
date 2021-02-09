#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
using namespace std;

auto DFSTrav(const vector<vector<size_t>> &graph, unordered_map<size_t, size_t> &lines, const size_t &src, const size_t dest) {
    vector<bool> visit(graph.size(), false);    
    vector<size_t> path, tempPath;
    size_t minTransfer = -1UL;
    function<void(const size_t &, const size_t &)> 
    DFS = [&graph, &lines, &visit, &path, &tempPath, &minTransfer, &DFS](const size_t &src, const size_t &dest){
        if(visit[src]) return;
        visit[src] = true; tempPath.emplace_back(src);
        if(src == dest) {
            size_t tempCnt = 0;
            for(size_t i = 1, prev = -1, next; i < tempPath.size(); ++i, prev = next) {
                if(prev != (next = lines[tempPath[i-1] << 32 | tempPath[i]])) ++tempCnt;
            }
            if(path.empty() || tempPath.size() < path.size() || (tempPath.size() == path.size() && tempCnt < minTransfer)){
                minTransfer = tempCnt; 
                path = tempPath;
            }
        }
        else for(const size_t &next : graph[src]) DFS(next, dest);
        visit[src] = false; tempPath.pop_back();
    };
    DFS(src, dest);
    return path;
}

int main() {
    size_t n, m;
    if(!scanf("%zu", &n)) return 0;
    vector<vector<size_t>> graph(10000);
    unordered_map<size_t, size_t> lines;
    for(size_t lineNo = 1, k, stop1; lineNo <= n && scanf("%zu%zu", &k, &stop1); ++lineNo) {
        for(size_t i = 1, stop2; i < k && scanf("%zu", &stop2); ++i, stop1 = stop2){
            graph[stop1].emplace_back(stop2);
            graph[stop2].emplace_back(stop1);
            lines[stop1 << 32 | stop2] = lines[stop2 << 32 | stop1] = lineNo;
        }
    }

    if(!scanf("%zu", &m)) return 0;
    for(size_t i = 0, u, v, prev; i < m && scanf("%zu%zu", &u, &v); ++i) {
        auto path = DFSTrav(graph, lines, u, v);
        prev = lines[path[0]<<32 | path[1]];
        printf("%zu\n", path.size()-1);
        for(size_t j = 1, next; j < path.size(); ++j) {
            if(prev != (next = lines[path[j] << 32 | path[j-1]])) {
                printf("Take Line#%zu from %04zu to %04zu.\n", prev, u, path[j-1]);
                prev = next; u = path[j-1];
            }
        }
        printf("Take Line#%zu from %04zu to %04zu.\n", prev, u, v);
    }
    return 0;
}