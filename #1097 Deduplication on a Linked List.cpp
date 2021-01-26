#include <iostream>
#include <vector>
using namespace std;
constexpr size_t MAXN = 100000;
typedef pair<ssize_t, ssize_t> Node; // val, next

int main() {
    ssize_t addr, n;
    if(scanf("%zd%zu", &addr, &n) != 2) return 0;
    
    vector<Node> nodes(MAXN + 1);
    for(ssize_t i = 0, now, val, nxt; i < n && scanf("%zd%zd%zd", &now, &val, &nxt) == 3; ++i) {
        nodes[now] = {val, nxt};
    }

    vector<ssize_t> next[2]{vector<ssize_t>(MAXN+1), vector<ssize_t>(MAXN + 1)};
    vector<bool> exists(10001, false); next[0][MAXN] = next[1][MAXN] = -1;
    for(ssize_t p = addr, rmIdx = MAXN, kpIdx = MAXN; p != -1; p = nodes[p].second) {
        if(exists[std::abs(nodes[p].first)]) next[1][rmIdx] = p, rmIdx = p, next[1][p] = -1;
        else next[0][kpIdx] = p, kpIdx = p, next[0][p] = -1, exists[std::abs(nodes[p].first)] = true;
    }

    for(size_t i = 0; i < 2; ++i) {
        for(ssize_t p = next[i][MAXN]; p != -1; p = next[i][p]) {
            if(next[i][p] == -1) printf("%05zd %zd -1\n", p, nodes[p].first);
            else printf("%05zd %zd %05zd\n", p, nodes[p].first, next[i][p]);
        }
    }
    return 0;
}