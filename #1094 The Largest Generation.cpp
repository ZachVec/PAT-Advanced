#include <iostream>
#include <queue>
using namespace std;
typedef vector<size_t> Children;

pair<size_t, unsigned> BFS(const vector<Children> &childrens, size_t rootId, unsigned rootLevel) {
    queue<size_t> q; 
    pair<size_t, unsigned> ans = {0, 0};
    for(q.push(rootId); !q.empty(); ++rootLevel) {
        if(q.size() > ans.second) ans = {q.size(), rootLevel};
        for(size_t sz = q.size(); sz--; q.pop()) {
            for(const size_t &childId : childrens[q.front()]) q.push(childId);
        }
    }
    return ans;
}

int main() {
    size_t n, m;
    if(scanf("%zu%zu", &n, &m) != 2) return 0;
    vector<Children> childrens(n+1);
    
    for(size_t i = 0, id, k; i < m && scanf("%zu%zu", &id, &k) == 2; ++i) {
        for(size_t j = 0, childId; j < k && scanf("%zu", &childId); ++j) {
            childrens[id].emplace_back(childId);
        }
    }

    auto ans = BFS(childrens, 1, 1);
    printf("%zu %u\n", ans.first, ans.second);
    return 0;
}