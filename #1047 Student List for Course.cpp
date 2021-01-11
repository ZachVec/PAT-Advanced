#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
char names[40000][5];
vector<size_t> courses[2500];

int main() {
    size_t n, k;
    if(!scanf("%zu%zu", &n, &k)) return 0;
    for(size_t i = 0, m; i < n && scanf("%s%zu", names[i], &m); ++i) 
        for(size_t j = 0, id; j < m && scanf("%zu", &id); ++j) 
            courses[id-1].emplace_back(i);

    for(size_t i = 0; i < k; ++i) {
        sort(courses[i].begin(), courses[i].end(), [](const size_t &a, const size_t &b) {
            return strcmp(names[a], names[b]) < 0;
        });
        printf("%zu %zu\n", i + 1, courses[i].size());
        for(const size_t &uid : courses[i]) printf("%s\n", names[uid]);
    }
    return 0;
}