#include <iostream>

int main() {
    size_t ans = 0;
    for(size_t i = 0, g, s, k; i < 2 && scanf("%zu.%zu.%zu", &g, &s, &k); ++i) 
        ans += g * 17 * 29 + s * 29 + k;
    printf("%zu.%zu.%zu\n", ans / 17 / 29, ans / 29 % 17, ans % 29);
    return 0;
}