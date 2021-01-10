#include <iostream>
#include <vector>
using namespace std;
size_t binarySearch(const vector<size_t> &arr, size_t val) {
    size_t l = 0, r = arr.size(), mid;
    while(l < r) {
        mid = (l + r) / 2;
        if(arr[mid] >= val) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    size_t n, payment, temp, minCost = -1;
    vector<size_t> sums, j;
    if(scanf("%zu%zu", &n, &payment) != 2) return 0;
    sums.emplace_back(0); j.emplace_back(0);
    for(size_t i = 0; i < n && scanf("%zu", &temp); ++i) 
        sums.emplace_back(sums.back() + temp);
    for(size_t i = 1; i <= n; ++i) {
        if((temp = binarySearch(sums, sums[i-1] + payment)) == n + 1) break;
        if((sums[temp] - sums[i-1]) < minCost) minCost = sums[temp] - sums[i-1];
        j.emplace_back(temp);
    }
    for(size_t i = 1; i < j.size(); ++i) {
        if(sums[j[i]] - sums[i-1] == minCost)
            printf("%zu-%zu\n", i, j[i]);
    }
    return 0;
}