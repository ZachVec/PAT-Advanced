#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    size_t n, k;
    if(scanf("%zu%zu", &k, &n) != 2) return 0;

    vector<int> preorder(n);
    unordered_set<int> numbers;
    for(size_t i = 0; i < n && scanf("%d", &preorder[i]); ++i) numbers.insert(preorder[i]);
    
    int u, v, root;
    auto between = [&u, &v](const int &root){ return (u <= root && root <= v) || (v <= root && root <= u); };
    for(size_t i = 0, count; i < k && scanf("%d%d", &u, &v); ++i) {
        if((count = numbers.count(u) + numbers.count(v)) == 0)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if(count == 1)
            printf("ERROR: %d is not found.\n", numbers.count(u) ? v : u);
        else {
            for(const int &node : preorder) if(between(root = node)) break;
            if(root == u || root == v) 
                printf("%d is an ancestor of %d.\n", root, root == u ? v : u);
            else 
                printf("LCA of %d and %d is %d.\n", u, v, root);
        }
    }
    return 0;
}