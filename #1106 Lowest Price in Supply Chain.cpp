#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
pair<unsigned, unsigned> BFS(const vector<vector<size_t>> &tree, const size_t &rootId){
    queue<size_t> q; q.emplace(rootId);
    for(unsigned level = 0, cnt = 0; !q.empty(); ++level) {
        for(size_t sz = q.size(); sz--; q.pop()) {
            if(tree[q.front()].empty()) ++cnt;
            else for(const size_t &id : tree[q.front()]) q.emplace(id);
        }
        if(cnt) return {level, cnt};
    }
    return {-1, -1};
}

int main() {
    size_t n; double p, r;
    if(scanf("%zu%lf%lf", &n, &p, &r) != 3) return 0;

    vector<vector<size_t>> childrens(n);
    for(size_t i = 0, k; i < n && scanf("%zu", &k); ++i) {
        for(size_t j = 0, id; j < k && scanf("%zu", &id); ++j) {
            childrens[i].emplace_back(id);
        }
    }

    auto ans = BFS(childrens, 0);
    printf("%.4f %u\n", p * pow(1+r/100, ans.first), ans.second);
    return 0;
}