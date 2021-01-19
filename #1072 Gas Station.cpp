#include <iostream>
#include <vector>
using namespace std;
typedef pair<size_t, unsigned> Node;
vector<Node> graph[1011];

bool dijkstra(size_t n, size_t m, size_t src, unsigned r, unsigned &minGapDist, unsigned &totalDist) {
    vector<bool> visit(n + m + 1, false);
    vector<unsigned> dist(n + m + 1, -1);
    dist[src] = 0;
    for(size_t i = 0; i < n + m; ++i) {
        size_t u = -1; unsigned dst = -1;
        for(size_t j = 1; j <= n + m; ++j) {
            if(!visit[j] && dist[j] < dst) {
                u = j;
                dst = dist[j];
            }
        }

        if(u == size_t(-1) || (u <= n && dist[u] > r)) return false;
        
        visit[u] = true;
        for(const Node &n : graph[u]) {
            if(visit[n.first]) continue;
            if(dist[u] + n.second < dist[n.first]) {
                dist[n.first] = dist[u] + n.second;
            }
        }
    }

    minGapDist = -1; totalDist = 0;
    for(size_t i = 1; i <= n; ++i) {
        totalDist += dist[i];
        minGapDist = min(dist[i], minGapDist);
    }
    return true;
}

int main() {
    size_t n, m, k, ansIdx = -1;
    unsigned range, dist;
    char s[5], d[5];

    if(scanf("%zu%zu%zu%u", &n, &m, &k, &range) != 4) return 0;
    auto toIndex = [n](const char buf[5]) { return buf[0] == 'G' ? n + atoi(buf+1) : atoi(buf); };

    for(size_t i = 0, u, v; i < k && scanf("%s%s%u", s, d, &dist); ++i) {
        u = toIndex(s); v = toIndex(d);
        graph[u].emplace_back(v, dist);
        graph[v].emplace_back(u, dist);
    }

    unsigned minTotalDist = -1, maxGapDist = 0;
    for(size_t i = n + 1; i <= n + m; ++i) {
        unsigned tTotalDist, tGapDist;
        if(!dijkstra(n, m, i, range, tGapDist, tTotalDist)) continue;
        if(tGapDist > maxGapDist) {
            ansIdx       = i;
            maxGapDist   = tGapDist;
            minTotalDist = tTotalDist;
        }
        else if(tGapDist == maxGapDist && tTotalDist < minTotalDist) {
            ansIdx       = i;
            minTotalDist = tTotalDist;
        }
    }
    if(ansIdx == size_t(-1)) printf("No Solution\n");
    else printf("G%zu\n%u.0 %.1f\n", ansIdx - n, maxGapDist, double(minTotalDist) / n);
    return 0;
}