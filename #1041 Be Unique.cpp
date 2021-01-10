#include <iostream>
using namespace std;

int main() {
    size_t n, idx;
    if(scanf("%zu", &n) != 1) return 0;
    size_t   *nums = new size_t[n];
    unsigned *cnts = new unsigned[10001]();
    for(size_t i = 0, num; i < n && scanf("%zu", &num); ++i) {
        nums[i] = num;
        ++cnts[num];
    }
    for(idx = 0; idx < n && cnts[nums[idx]] != 1; ++idx);
    if(idx == n) printf("None\n");
    else printf("%zu\n", nums[idx]);
    delete[] nums;
    delete[] cnts;
    return 0;
}