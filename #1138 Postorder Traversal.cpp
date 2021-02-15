#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    size_t n, idx = 0;
    int number;
    if(!scanf("%zu", &n)) return 0;
    
    vector<int> pre(n);
    unordered_map<int, size_t> index;
    for(size_t i = 0; i < n && scanf("%d", &pre[i]); ++i);  // pre-order
    for(size_t i = 0; i < n && scanf("%d", &number); ++i) index[number] = i;
    for(size_t lo = 0, hi = n-1, rootIndex; lo < hi; ++idx) {
        if((rootIndex = index[pre[idx]]) == lo) lo = rootIndex + 1; // no left subtree, then go right subtree
        else hi = rootIndex - 1; // left subtree exists, then go left subtree
    }
    printf("%d\n", pre[idx]);
    return 0;
}