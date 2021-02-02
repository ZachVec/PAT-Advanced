#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n, m, k;
    if(scanf("%zu%zu", &n, &m) != 2) return 0;

    vector<vector<bool>> isConnected(n+1, vector<bool>(n+1, false));
    for(size_t i = 0, u, v; i < m && scanf("%zu%zu", &u, &v); ++i) {
        isConnected[u][v] = isConnected[v][u] = true;
    }

    if(!scanf("%zu", &k)) return 0;
    for(size_t i = 0, sz, front, back; i < k && scanf("%zu%zu", &sz, &front); ++i) {
        bool isHamiltonianCycle = sz == n + 1;
        vector<bool> hasVisit(n + 1, false);
        for(size_t prev = front; --sz && scanf("%zu", &back); prev = back) {
            if(!isHamiltonianCycle) continue;
            isHamiltonianCycle = isHamiltonianCycle && !hasVisit[back] && isConnected[prev][back];
            hasVisit[back] = true;
        }
        printf("%s\n", isHamiltonianCycle && front == back ? "YES" : "NO");
    }
    return 0;
}