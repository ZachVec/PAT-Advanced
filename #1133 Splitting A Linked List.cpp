#include <iostream>
#include <vector>
typedef std::pair<int, size_t> Node;

int main() {
    int data, k;
    size_t addr, n;
    if(scanf("%zu%zu%d", &addr, &n, &k) != 3) return 0;

    std::vector<Node> list(100000), ret; // data, next
    for(size_t i = 0, now, nxt; i < n && scanf("%zu%d%zu", &now, &data, &nxt); ++i) list[now] = {data, nxt};
    for(size_t p = addr; p != -1UL; p = list[p].second) 
        if(list[p].first < 0) ret.emplace_back(list[p].first, p);
    for(size_t p = addr; p != -1UL; p = list[p].second) 
        if(0 <= list[p].first && list[p].first <= k) ret.emplace_back(list[p].first, p);
    for(size_t p = addr; p != -1UL; p = list[p].second) 
        if(list[p].first > k) ret.emplace_back(list[p].first, p);
    for(auto it = ret.begin(), end = ret.end() - 1; it != end; ++it)
        printf("%05zu %d %05zu\n", it->second, it->first, (it+1)->second);
    printf("%05zu %d -1\n", ret.back().second, ret.back().first); 
    return 0;
}