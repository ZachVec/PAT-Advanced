#include <iostream>
#include <algorithm>
constexpr size_t MAXN = 1000;
unsigned sorted[MAXN], ans[MAXN];
void inorder(size_t root, size_t n, size_t &index) {
    if(root >= n) return;
    inorder(2 * root + 1, n, index);
    ans[root] = sorted[index++];
    inorder(2 * root + 2, n, index);
}

int main() {
    size_t n, index = 0;
    if(!scanf("%zu", &n)) return 0;
    for(size_t i = 0; i < n && scanf("%u", &sorted[i]); ++i);
    std::sort(sorted, sorted + n);
    inorder(0, n, index);
    for(size_t i = 0; i < n; ++i) {
        printf("%u%c", ans[i], " \n"[i == n - 1]);
    }
    return 0;
}