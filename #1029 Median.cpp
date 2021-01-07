#include <iostream>
int a[200000], b[200000];

int main() {
    int ans;
    size_t n1, n2, m;
    if(scanf("%zu", &n1) != 1) return 0;
    for(size_t i = 0; i < n1 && scanf("%d", &a[i]); ++i);
    if(scanf("%zu", &n2) != 1) return 0;
    for(size_t i = 0; i < n2 && scanf("%d", &b[i]); ++i);
    m = (n1 + n2 - 1) / 2;
    for(size_t k = 0, i = 0, j = 0; k <= m; ++k) {
        if(i == n1)             ans = b[j++];
        else if(j == n2)        ans = a[i++];
        else if(a[i] < b[j])    ans = a[i++];
        else                    ans = b[j++];
    }
    printf("%u\n", ans);
    return 0;
}