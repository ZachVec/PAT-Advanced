#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    size_t n, m;
    if(scanf("%zu%zu", &n, &m) != 2) return 0;

    unordered_map<size_t, vector<size_t>> incompatibles;
    for(size_t i = 0, u, v; i < n && scanf("%zu%zu", &u, &v) == 2; ++i) {
        incompatibles[u].emplace_back(v);
        incompatibles[v].emplace_back(u);
    }

    for(size_t i = 0, k; i < m && scanf("%zu", &k); ++i) {
        bool isSafe = true;
        vector<bool> isDangerous(100000, false);
        for(size_t j = 0, goods; j < k && scanf("%zu", &goods); ++j) {
            if(isDangerous[goods]) isSafe = false;
            for(const size_t &incompatible : incompatibles[goods]) {
                isDangerous[incompatible] = true;
            }
        }
        printf("%s\n", isSafe ? "Yes" : "No");
    }
    return 0;
}