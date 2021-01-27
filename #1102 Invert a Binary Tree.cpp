#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<ssize_t, ssize_t> Children;

void levelOrder(const vector<Children> &tree, vector<ssize_t> &ans, const ssize_t &root) {
    queue<ssize_t> q;
    for(q.emplace(root); !q.empty(); q.pop()) {
        if(q.front() == -1) continue;
        ans.emplace_back(q.front());
        q.emplace(tree[q.front()].first);
        q.emplace(tree[q.front()].second);
    }
}

void inOrder(const vector<Children> &tree, vector<ssize_t> &ans, const ssize_t &root) {
    if(root == -1) return;
    inOrder(tree, ans, tree[root].first);
    ans.emplace_back(root);
    inOrder(tree, ans, tree[root].second);
}

int main() {
    size_t n, root;
    if(!scanf("%zu%*c", &n)) return 0;
    char l, r;
    vector<bool>     notRoot(n);
    vector<Children> childrens(n);
    for(size_t i = 0; i < n && scanf("%c%*c%c%*c", &r, &l); ++i) {
        childrens[i].first  = isdigit(l) ? l - '0' : -1;
        childrens[i].second = isdigit(r) ? r - '0' : -1;
        if(childrens[i].first  != -1) notRoot[childrens[i].first]  = true;
        if(childrens[i].second != -1) notRoot[childrens[i].second] = true;
    }
    for(root = 0; root < n && notRoot[root]; ++root);
    vector<ssize_t> ans;
    ans.clear(); levelOrder(childrens, ans, root);
    for(size_t i = 0; i < ans.size(); ++i) printf("%zd%c", ans[i], " \n"[i == ans.size() - 1]);
    ans.clear(); inOrder(childrens, ans, root);
    for(size_t i = 0; i < ans.size(); ++i) printf("%zd%c", ans[i], " \n"[i == ans.size() - 1]);
    return 0;
}