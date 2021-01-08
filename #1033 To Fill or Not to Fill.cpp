#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<double, unsigned> Station; // price, dist

int main() {
    size_t n, now = 0;
    unsigned Cap, Dist, Davg;

    if(scanf("%u%u%u%zu", &Cap, &Dist, &Davg, &n) != 4) return 0;
    vector<Station> nodes(n);
    for(Station &s : nodes) if(scanf("%lf%u", &s.first, &s.second) != 2) return 0;
    nodes.emplace_back(0, Dist);

    sort(nodes.begin(), nodes.end(), [](const Station &a, const Station &b) {
        return a.second < b.second;     // sort according to dist increasingly
    });

    if(nodes.empty() || nodes.front().second != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    double tank = 0, cost = 0;
    unsigned range = Cap * Davg;
    for(size_t nxt = -1; now != n; now = nxt, nxt = -1) {
        for(size_t i = now + 1; i <= n && nodes[i].second <= nodes[now].second + range; ++i) {
            if(nxt == size_t(-1) || nodes[i].first < nodes[nxt].first) nxt = i;
            if(nodes[nxt].first < nodes[now].first) break;
        }
        if(nxt == size_t(-1)) break;
        if(nodes[nxt].first < nodes[now].first) { // next station cheaper
            if((tank -= double(nodes[nxt].second - nodes[now].second) / Davg) < 0) {
                cost += nodes[now].first * (-tank);
                tank = 0;
            }
        }
        else {
            cost += (double(Cap) - tank) * nodes[now].first;
            tank = double(Cap) - double(nodes[nxt].second - nodes[now].second) / Davg;
        }
    }
    if(now == n) printf("%.2f\n", cost);
    else printf("The maximum travel distance = %u.00\n", nodes[now].second + range);
    return 0;
}