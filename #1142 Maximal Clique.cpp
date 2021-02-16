#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    size_t nv, ne, nq;
    if(scanf("%zu%zu", &nv, &ne) != 2) return 0;

    vector<vector<bool>> isAdj(nv + 1, vector<bool>(nv + 1, false));
    for(size_t i = 0, u, v; i < ne && scanf("%zu%zu", &u, &v); ++i) isAdj[u][v] = isAdj[v][u] = true;
    
    if(!scanf("%zu", &nq)) return 0;
    unordered_set<size_t> clique;
    for(size_t i = 0, k; i < nq && scanf("%zu", &k); ++i) {
        bool inSetAdj = true, outSetAdj = false; clique.clear();
        for(size_t j = 0, u; j < k && scanf("%zu", &u); ++j) {
            for(const size_t &v : clique) inSetAdj = inSetAdj && isAdj[u][v];
            clique.emplace(u);
        }
        
        if(!inSetAdj) { printf("Not a Clique\n"); continue; }
        for(size_t u = 1; u <= nv && !outSetAdj; ++u) {
            if(clique.count(u)) continue;
            outSetAdj = true;
            for(const size_t &v : clique) outSetAdj = outSetAdj && isAdj[u][v];
        }
        printf("%s\n", outSetAdj ? "Not Maximal" : "Yes");
    }
    return 0;
}