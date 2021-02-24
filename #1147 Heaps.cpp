#include <iostream>
#include <vector>
void postOrder(const std::vector<int> &values, const size_t &root, std::vector<int> &ans){
    if(root >= values.size()) return;
    postOrder(values, 2 * root + 1, ans);
    postOrder(values, 2 * root + 2, ans);
    ans.emplace_back(values[root]);
}

int main() {
    size_t n, k;
    if(scanf("%zu%zu", &n, &k) != 2) return 0;

    std::vector<int> values(k);
    std::vector<int> traversal;
    bool isMaxRoot, isMaxRecur;
    for(size_t i = 0; i < n; ++i) {
        traversal.clear();
        for(size_t j = 0; j < k && scanf("%d", &values[j]); ++j);
        isMaxRoot = isMaxRecur = values[0] >= values[1];
        for(size_t j = 1; j < k && isMaxRoot == isMaxRecur; ++j) isMaxRecur = values[(j-1)/2] >= values[j];
        if(isMaxRoot == isMaxRecur) printf("%s\n", isMaxRoot ? "Max Heap" : "Min Heap");
        else printf("Not Heap\n");
        postOrder(values, 0, traversal);
        for(size_t j = 0; j < k; ++j) printf("%d%c", traversal[j], " \n"[j == k-1]);
    }
    return 0;
}