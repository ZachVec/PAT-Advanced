#include <iostream>
#include <algorithm>

int main() {
    size_t n, idx1, idx2;
    int ori[101], srt[101];
    if(!scanf("%zu", &n)) return 0;
    for(size_t i = 0; i < n && scanf("%d", &ori[i]); ++i);
    for(size_t i = 0; i < n && scanf("%d", &srt[i]); ++i);
    for(idx1 = 1; idx1 < n && srt[idx1-1] <= srt[idx1]; ++idx1);
    for(idx2 = idx1; idx2 < n && ori[idx2] == srt[idx2]; ++idx2);
    if(idx2 == n) {
        printf("Insertion Sort\n");
        std::sort(srt, srt + idx1 + 1);
    }
    else {
        printf("Heap Sort\n");
        for(idx1 = n - 1; idx1 < n && srt[idx1] > srt[0]; --idx1);
        std::swap(srt[0], srt[idx1]);
        for(size_t root = 0, gChild = 1; gChild < idx1; root = gChild, gChild = gChild * 2 + 1) {
            if(gChild + 1 < idx1 && srt[gChild+1] > srt[gChild]) ++gChild;
            if(srt[root] >= srt[gChild]) break;
            else std::swap(srt[root], srt[gChild]);
        }
    }
    for(size_t i = 0; i < n; ++i) printf("%d%c", srt[i], " \n"[i == n-1]);
    return 0;
}