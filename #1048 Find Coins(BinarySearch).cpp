#include <iostream>
#include <algorithm>
using namespace std;
size_t binarySearch(unsigned arr[], size_t l, size_t r, unsigned val) {
    size_t mid;
    while(l <= r) {
        mid = (l + r) / 2;
        if(arr[mid] == val) return mid;
        else if(arr[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    size_t n; 
    unsigned amount, *values;

    if(!scanf("%zu%u", &n, &amount)) return 0;
    values = new unsigned[n];
    for(size_t i = 0; i < n; ++i) if(!scanf("%u", &values[i])) return 0;

    sort(values, values + n, less<unsigned>());
    for(size_t i = 0, j; i < n && 2 * values[i] <= amount; ++i) {
        j = binarySearch(values, i + 1, n - 1, amount - values[i]);
        if(j != size_t(-1)) {
            printf("%u %u\n", values[i], values[j]);
            delete[] values;
            return 0;
        }
    }
    printf("No Solution\n");
    delete[] values;
    return 0;
}