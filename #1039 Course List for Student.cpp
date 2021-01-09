#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr int MAXN = 26 * 26 * 26 * 10;
vector<unsigned> courses[MAXN];
size_t hashIdx(char name[5]) {
    size_t ret = 0;
    for(size_t i = 0; i < 3; ++i) 
        ret = ret * 26 + (name[i] - 'A');
    return ret * 10 + (name[3] - '0');
}

int main() {
    size_t m, n;
    char name[5];
    unsigned id;
    if(scanf("%zu%zu", &m, &n) != 2) return 0;
    for(size_t i = 0, k; i < n && scanf("%u%zu", &id, &k); ++i) {
        for(size_t j = 0; j < k && scanf("%s", name); ++j) 
            courses[hashIdx(name)].emplace_back(id);
    }
    for(size_t i = 0; i < m && scanf("%s", name); ++i) {
        auto &ids = courses[hashIdx(name)];
        sort(ids.begin(), ids.end());
        printf("%s %zu", name, ids.size());
        for(const unsigned id : ids) printf(" %u", id);
        putchar('\n');
    }
    return 0;
}