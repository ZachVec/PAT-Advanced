#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n, m, q;
    vector<bool> vertices;
    vector<pair<size_t, size_t>> edges;
    if(scanf("%zu%zu", &n, &m) != 2) return 0;

    vertices.resize(n); edges.reserve(m);
    for(size_t i = 0, u, v; i < m && scanf("%zu%zu", &u, &v); ++i) edges.emplace_back(u, v);

    if(!scanf("%zu", &q)) return 0;
    for(size_t i = 0, k; i < q && scanf("%zu", &k); ++i) {
        bool isVCover = true;
        vertices.assign(vertices.size(), false);
        for(size_t j = 0, v; j < k && scanf("%zu", &v); ++j) vertices[v] = true;
        for(const auto &edge : edges) isVCover = isVCover && (vertices[edge.first] || vertices[edge.second]);
        printf("%s\n", isVCover ? "Yes" : "No");
    }
    return 0;
}