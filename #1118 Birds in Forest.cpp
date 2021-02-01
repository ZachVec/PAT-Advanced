#include <iostream>
#include <vector>
using namespace std;

struct weightedUnionFind{
    size_t treeCnt, nodeCnt;
    vector<size_t> rootOf, size;  // root, size
    
    weightedUnionFind(const size_t &n) : treeCnt(0), nodeCnt(0) {
        rootOf.resize(n+1); size.resize(n+1);
        for(size_t i = 0; i <= n; ++i) rootOf[i] = 0, size[i] = 1;
    }

    size_t Find(size_t x) {
        while(x != rootOf[x]) x = rootOf[x];
        return x;
    }

    void Union(size_t x, size_t y){
        size_t rootOfx = Find(x), rootOfy = Find(y);
        if(rootOfx == rootOfy) return;

        if(size[rootOfx] > size[rootOfy]) {
            size[rootOfx]  += size[rootOfy];
            rootOf[rootOfy] =  rootOfx;
        }
        else {
            size[rootOfy]  += size[rootOfx];
            rootOf[rootOfx] = rootOfy;
        }
        --treeCnt;
    }

    bool init(size_t x) {
        if(x < rootOf.size() && !rootOf[x]) rootOf[x] = x, ++treeCnt, ++nodeCnt;
        return x < rootOf.size(); 
    }
    inline bool connected(const size_t &x, const size_t &y) { return Find(x) == Find(y); }
};

int main() {
    size_t n, query;
    if(!scanf("%zu", &n)) return 0;

    weightedUnionFind wuf(10000);
    for(size_t i = 0, k, birdi; i < n && scanf("%zu%zu", &k, &birdi) && wuf.init(birdi); ++i) {
        for(size_t j = 1, birdj; j < k && scanf("%zu", &birdj) && wuf.init(birdj); ++j) {
            wuf.Union(birdi, birdj);
        }
    }

    printf("%zu %zu\n", wuf.treeCnt, wuf.nodeCnt);
    if(!scanf("%zu", &query)) return 0;
    for(size_t i = 0, birdi, birdj; i < query && scanf("%zu%zu", &birdi, &birdj); ++i) {
        printf("%s\n", wuf.connected(birdi, birdj) ? "Yes" : "No");
    }
    return 0;
}