#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    size_t n, m, k;
    if(scanf("%zu%zu", &n, &m) != 2) return 0;

    char p1[6], p2[6];
    vector<bool> gender(10000);
    vector<unordered_set<size_t>> friends(10000);
    for(size_t i = 0, u, v; i < m && scanf("%s %s\n", p1, p2); ++i) {
        gender[u = abs(atoi(p1))] = isdigit(p1[0]);
        gender[v = abs(atoi(p2))] = isdigit(p2[0]);
        friends[u].insert(v); friends[v].insert(u);
    }

    if(!scanf("%zu", &k)) return 0;
    vector<pair<size_t, size_t>> media;
    for(size_t i = 0, u, v; i < k && scanf("%s %s\n", p1, p2); ++i) {
        u = abs(atoi(p1)); v = abs(atoi(p2)); media.clear();
        for(const size_t &f1 : friends[u]) {
            if(gender[f1] != gender[u] || f1 == v) continue;
            for(const size_t &f2 : friends[f1]) {
                if(gender[f2] != gender[v] || f2 == u || f2 == v) continue;
                if(friends[f2].count(v)) media.emplace_back(f1, f2);
            }
        }
        sort(media.begin(), media.end(), less<pair<size_t, size_t>>());
        printf("%zu\n", media.size());
        for(const auto &kv : media) printf("%04zu %04zu\n", kv.first, kv.second);
    }
    return 0;
}