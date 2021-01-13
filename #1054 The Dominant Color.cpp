#include <iostream>

int main() {
    size_t n, m;
    unsigned cnt = 0, domColor, color;
    if(scanf("%zu%zu", &n, &m) != 2) return 0;
    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < m && scanf("%u", &color); ++j) {
            if(cnt == 0) {
                domColor = color;
                cnt = 1;
            }
            else cnt += (color == domColor ? 1 : -1);
        }
    }
    printf("%u\n", domColor);
    return 0;
}