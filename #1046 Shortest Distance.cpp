#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n, m;

    if(!scanf("%zu", &n)) return 0;
    vector<unsigned> dist(n + 2, 0);
    for(size_t i = 2; i < n + 2; ++i)
        if(!scanf("%u", &dist[i])) return 0;
    for(size_t i = 2; i < n + 2; ++i) 
        dist[i] += dist[i-1];

    if(!scanf("%zu", &m)) return 0;
    for(size_t i = 0, u, v; i < m && scanf("%zu%zu", &u, &v); ++i) {
        if(u > v) swap(u, v);
        printf("%u\n", min(dist[v] - dist[u], dist[n+1] - dist[v] + dist[u]));
    }
    return 0;
}