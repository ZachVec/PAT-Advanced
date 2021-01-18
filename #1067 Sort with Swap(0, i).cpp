#include <iostream>

int main() {
    size_t n, k = 0, *index;
    unsigned disorder = 0, cnt = 0;
    if(!scanf("%zu", &n)) return 0;
    index = new size_t[n];
    for(size_t i = 0, num; i < n && scanf("%zu", &num); ++i) {
        index[num] = i;
        if(num != i) ++disorder;
    }
    while(disorder > 1) {
        if(index[0] == 0) {
            while(index[k] == k) ++k;
            std::swap(index[0], index[k]);
            ++cnt;
        }
        while(index[0] != 0) {
            std::swap(index[0], index[index[0]]);
            --disorder; ++cnt;
        }
    }
    delete[] index;
    printf("%u\n", cnt);
    return 0;
}