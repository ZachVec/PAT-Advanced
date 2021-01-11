#include <iostream>
#include <array>
using namespace std;
array<size_t, 501> cnts;

int main() {
    size_t n, amount;
    if(!scanf("%zu%zu", &n, &amount)) return 0;
    cnts.fill(0);
    for(size_t i = 0, value; i < n && scanf("%zu", &value); ++i)
        ++cnts[value];
    for(size_t i = 0, j; i < 501; ++i) {
        if(!cnts[i] || (j = amount - i) > 500) continue;
        if(cnts[j] > (i == j ? 1 : 0)) {
            printf("%zu %zu\n", i, j);
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}