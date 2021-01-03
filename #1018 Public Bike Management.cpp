#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<size_t, size_t> Node; // dest, dist
constexpr size_t MAXN = 501;
int            status[MAXN];
vector<Node>   graph[MAXN];
vector<size_t> pre[MAXN], ans, tempAns;
int minNeed = 0x7FFFFFFF, minRemain = 0x7FFFFFFF;

void DFS(size_t src, size_t now) {   
    tempAns.push_back(now);
    if(now == src) {
        int remain = 0, need = 0;
        for(auto it = tempAns.rbegin() + 1; it != tempAns.rend(); ++it) {
            if((remain += status[*it]) < 0) {
                need -= remain;
                remain = 0;
            }
        }
        bool flag1 = need < minNeed;
        bool flag2 = need == minNeed && remain < minRemain;
        if(flag1 || flag2) {
            minNeed = need;
            minRemain = remain;
            ans = tempAns;
        }
    }
    else {
        for(const size_t &prev : pre[now])
            DFS(src, prev);
    }
    tempAns.pop_back();
}

void dijkstra(size_t n, size_t dest){
    vector<bool>   vis(n+1, false);
    vector<size_t> dis(n+1, -1);
    dis[0] = 0;
    for(size_t i = 0, u, mdis; i <= n; ++i) {
        u = mdis = -1;
        for(size_t j = 0; j <= n; ++j) {
            if(vis[j] || dis[j] >= mdis) continue; 
            u = j; mdis = dis[j];
        }

        if(u == -1) return;
        vis[u] = true;
        for(const Node &n : graph[u]) {
            if(vis[n.first] || dis[n.first] < mdis + n.second)
                continue;
            if(dis[n.first] > mdis + n.second) {
                dis[n.first] = mdis + n.second;
                pre[n.first].clear();
                pre[n.first].push_back(u);
            }
            else pre[n.first].push_back(u);
        }
    }
}

int main() {
    size_t cap, n, dest, m;
    if(scanf("%zu%zu%zu%zu", &cap, &n, &dest, &m) == EOF) return 0;
    for(size_t i = 1; i <= n; ++i) scanf("%d", &status[i]);
    for(size_t i = 1; i <= n; ++i) status[i] -= int(cap) / 2;
    for(size_t i = 0, u, v, d; i < m; ++i) {
        scanf("%zu%zu%zu", &u, &v, &d);
        graph[u].emplace_back(v, d);
        graph[v].emplace_back(u, d);
    }
    dijkstra(n, dest);
    DFS(0, dest);
    printf("%d 0", minNeed);
    for(auto it = ans.rbegin() + 1; it != ans.rend(); ++it) {
        printf("->%zu", *it);
    }
    printf(" %d\n", minRemain);
    return 0;
}

/*
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1

Capacity, # of Stations, index of problematic station, # of Roads
3 0->2->3 0
*/