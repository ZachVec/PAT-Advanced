#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, size_t> Node; // val, next or addr;
Node nodes[100000];

int main() {
    int val;
    size_t n, addr;
    vector<Node> ans;
    if(scanf("%zu%zu", &n, &addr) != 2) return 0;
    for(size_t i = 0, now, nxt; i < n && scanf("%zu%d%zu", &now, &val, &nxt); ++i) 
        nodes[now] = {val, nxt};
    if(addr == size_t(-1)) printf("0 -1\n");
    else {
        for(size_t p = addr; p != size_t(-1); p = nodes[p].second) 
            ans.emplace_back(nodes[p].first, p);
        sort(ans.begin(), ans.end(), [](const Node &a, const Node &b) {
            return a.first > b.first;
        });
        printf("%zu %05zu\n", ans.size(), ans.back().second);
        for(size_t i = ans.size() - 1; i != 0; --i)
            printf("%05zu %d %05zu\n", ans[i].second, ans[i].first, ans[i-1].second);
        printf("%05zu %d -1\n", ans.front().second, ans.front().first);
    }
    return 0;
}