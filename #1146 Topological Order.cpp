#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t nv, ne, k;
    if(scanf("%zu%zu", &nv, &ne) != 2) return 0;

    vector<size_t> inDegree(nv + 1, 0), ans;
    vector<vector<size_t>> graph(nv + 1);
    for(size_t i = 0, u, v; i < ne && scanf("%zu%zu", &u, &v); ++i) {
        graph[u].emplace_back(v); ++inDegree[v];
    }

    if(!scanf("%zu", &k)) return 0;
    for(size_t i = 0; i < k; ++i) {
        bool isTopological = true;
        vector<size_t> degree = inDegree;
        for(size_t j = 0, v; j < nv && scanf("%zu", &v); ++j) {
            isTopological = isTopological && degree[v] == 0;
            for(const size_t &child : graph[v]) --degree[child];
        }
        if(!isTopological) ans.emplace_back(i);
    }
    for(size_t i = 0; i < ans.size(); ++i) printf("%zu%c", ans[i], " \n"[i == ans.size() - 1]);
    return 0;
}