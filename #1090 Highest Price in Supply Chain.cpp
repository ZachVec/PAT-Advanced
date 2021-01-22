#include <iostream>
#include <queue>
typedef std::vector<std::vector<size_t>> Tree;
typedef std::pair<double, unsigned> Answer;

Answer BFS(const Tree &tree, size_t root, double price, double rate) {
    Answer ans = {0.0, 0};
    std::queue<size_t> q;
    for(q.push(root); !q.empty(); price *= (1 + rate)) {
        for(size_t sz = q.size(); sz--; q.pop()) {
            if(tree[q.front()].empty()) {
                if(price > ans.first) ans = {price, 1};
                else ++ans.second;
            }
            for(const size_t &n : tree[q.front()]) q.push(n);
        }
    }
    return ans;
}

int main() {
    size_t n, root = 0; double price, rate;
    if(scanf("%zu%lf%lf", &n, &price, &rate) != 3) return 0;

    Tree tree(n);
    for(size_t i = 0, pid; i < n && scanf("%zu", &pid); ++i) {
        if(pid == size_t(-1)) root = i;
        else tree[pid].emplace_back(i);
    }
    Answer ans = BFS(tree, root, price, rate / 100);
    printf("%.2f %u\n", ans.first, ans.second);
    return 0;
}