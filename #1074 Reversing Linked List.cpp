#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, size_t> Node;
Node nodes[100000];

int main() {
    int data;
    size_t addr, n, k;
    vector<size_t> idx;
    if(scanf("%zu%zu%zu", &addr, &n, &k) != 3) return 0;
    for(size_t i = 0, now, nxt; i < n && scanf("%zu%d%zu", &now, &data, &nxt); ++i) nodes[now] = {data, nxt};
    for(size_t i = addr; i != size_t(-1); i = nodes[i].second) idx.emplace_back(i);
    for(size_t i = 0; i + k - 1 < idx.size(); i += k) { // loop if #remaining nodes >= k 
        for(size_t j = i + k - 1; j > i; --j) printf("%05zu %d %05zu\n", idx[j], nodes[idx[j]].first, idx[j-1]);
        if(i + k >= idx.size()) printf("%05zu %d -1\n", idx[i], nodes[idx[i]].first);
        else if(i + 2 * k - 1 < idx.size()) printf("%05zu %d %05zu\n", idx[i], nodes[idx[i]].first, idx[i + 2 * k - 1]);
        else printf("%05zu %d %05zu\n", idx[i], nodes[idx[i]].first, idx[i + k]);
    }
    for(size_t i = idx.size() - idx.size() % k; i < idx.size(); ++i) {
        if(i == idx.size() - 1) printf("%05zu %d -1\n", idx[i], nodes[idx[i]].first);
        else printf("%05zu %d %05zu\n", idx[i], nodes[idx[i]].first, idx[i + 1]);
    }
    return 0;
}