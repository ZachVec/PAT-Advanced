#include <iostream>
#include <vector>
#include <queue>
using namespace std;

pair<bool, ssize_t> isCompleteTree(const vector<pair<ssize_t, ssize_t>> &tree, const ssize_t &root) {
    bool flag = false; // -1 shown
    ssize_t ret = root;
    queue<ssize_t> q; 
    for(q.emplace(root); !q.empty(); q.pop()) {
        if(q.front() == -1) { flag = true; continue; }
        else if(flag) return { false, root };
        else ret = q.front();
        q.emplace(tree[ret].first);
        q.emplace(tree[ret].second);
    }
    return {true, ret};
}

int main() {
    ssize_t n, root;
    if(!scanf("%zd%*c", &n)) return 0;
    
    char l[3], r[3];
    vector<bool> notRoot(n);
    vector<pair<ssize_t, ssize_t>> tree(n);
    for(ssize_t i = 0; i < n && scanf("%s%*c%s%*c", l, r); ++i) {
        tree[i].first  = isdigit(l[0]) ? atoi(l) : -1;
        tree[i].second = isdigit(r[0]) ? atoi(r) : -1;
        if(tree[i].first  != -1) notRoot[tree[i].first]  = true; 
        if(tree[i].second != -1) notRoot[tree[i].second] = true; 
    }
    for(root = 0; root < n && notRoot[root]; ++root);
    auto ans = isCompleteTree(tree, root);
    printf("%s %zd\n", ans.first ? "YES" : "NO", ans.second);
    return 0;
}