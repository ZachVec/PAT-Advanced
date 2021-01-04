#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
typedef pair<size_t, size_t> Node;
unsigned post[30], in[30];
unordered_map<unsigned, size_t> inMap;
Node tree[30];

size_t buildTree(size_t postL, size_t inL, size_t len) {
    if(len == 0) return -1;
    size_t rootIdx = inMap[post[postL + len - 1]];
    tree[rootIdx].first  = buildTree(postL, inL, rootIdx - inL);
    tree[rootIdx].second = buildTree(postL + rootIdx - inL, rootIdx + 1, len - 1 + inL - rootIdx);
    return rootIdx;
}

int main() {
    size_t n, rootIdx;
    unsigned val;
    queue<size_t> q;
    if(scanf("%zu", &n) == EOF) return 0;
    for(size_t i = 0; i < n; ++i) scanf("%u", &post[i]);
    for(size_t i = 0; i < n; ++i) scanf("%u", &in[i]);
    for(size_t i = 0; i < n; ++i) inMap[in[i]] = i;
    rootIdx = buildTree(0, 0, n);
    for(q.push(rootIdx); !q.empty(); q.pop()) {
        const size_t idx = q.front();
        printf("%u", in[idx]);
        if(tree[idx].first  != -1) q.push(tree[idx].first);
        if(tree[idx].second != -1) q.push(tree[idx].second);
        printf("%c", q.size() == 1 ? '\n' : ' ');
    }
    return 0;
}

/*
7
2 3 1 5 7 6 4
1 2 3 4 5 6 7

4 1 6 3 5 7 2
*/