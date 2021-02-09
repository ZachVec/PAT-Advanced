    #include <iostream>
    #include <queue>
    using namespace std;
    constexpr size_t notExist = -1UL;
    struct Node{
        size_t l, r;
        int val;
        bool isBlack;
    };
    size_t nBlackNodes(const vector<Node> &nodes, const size_t &idx) {
        if(idx == notExist) return 1;
        return max(nBlackNodes(nodes, nodes[idx].l), nBlackNodes(nodes, nodes[idx].r)) + (nodes[idx].isBlack ? 1 : 0);
    }

    int main() {
        int number;
        size_t n;
        if(!scanf("%zu", &n)) return 0;
        vector<Node> nodes(30);
        auto insert = [&nodes](size_t root, size_t idx) {
            size_t child = root;
            while(child != notExist) {
                root = child;
                child = nodes[idx].val <= nodes[root].val ? nodes[root].l : nodes[root].r;
            }
            if(nodes[idx].val <= nodes[root].val) nodes[root].l = idx;
            else nodes[root].r = idx;
        };

        bool isRBTree;
        for(size_t i = 0, k; i < n && scanf("%zu", &k); ++i) {
            for(size_t j = 0; j < k && scanf("%d", &number); ++j) {
                nodes[j] = {notExist, notExist, abs(number), number >= 0};
            }
            for(size_t j = 1; j < k; ++j) insert(0, j);
            queue<size_t> q; isRBTree = nodes.front().isBlack;
            for(q.emplace(0); !q.empty() && isRBTree; q.pop()) {
                if(q.front() == notExist) continue;
                const Node &node = nodes[q.front()];
                if(!node.isBlack) {
                    if(node.l != notExist) isRBTree = isRBTree && nodes[node.l].isBlack;
                    if(node.r != notExist) isRBTree = isRBTree && nodes[node.r].isBlack;
                }
                isRBTree = isRBTree && nBlackNodes(nodes, node.l) == nBlackNodes(nodes, node.r);
                q.emplace(node.l); q.emplace(node.r);
            }
            printf("%s\n", isRBTree ? "Yes" : "No");
        }
        return 0;
    }