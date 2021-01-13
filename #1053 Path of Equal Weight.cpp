#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr size_t MAXN = 101;
size_t weight[MAXN];
vector<size_t> ans, tree[MAXN];

void DFS(size_t root, size_t w) { // assuming w >= 0
    ans.emplace_back(root);
    if(w == 0) {
        if(tree[root].empty()) {
            for(size_t i = 0, j = ans.size() - 1; i <= j; ++i) 
                printf("%zu%c", weight[ans[i]], i != j ? ' ' : '\n');
        }
    }
    else {
        for(const size_t &sid : tree[root]) {
            if(w < weight[sid]) continue;
            DFS(sid, w - weight[sid]);
        }
    }
    ans.pop_back();
}

int main() {
    size_t n, m, w;
    if(scanf("%zu%zu%zu", &n, &m, &w) != 3) return 0;
    for(size_t i = 0; i < n && scanf("%zu", &weight[i]); ++i);
    for(size_t i = 0, id, k; i < m && scanf("%zu%zu", &id, &k); ++i) {
        for(size_t j = 0, sid; j < k && scanf("%zu", &sid); ++j)
            tree[id].emplace_back(sid);
        sort(tree[id].begin(), tree[id].end(), [](const size_t &a, const size_t &b) {
            return weight[a] > weight[b];
        });
    }
    if(w < weight[0]) return 0;
    DFS(0, w - weight[0]);
    return 0;
}