#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(const size_t &n) {
    size_t uplimit = sqrt(n);
    for(size_t i = 2; i <= uplimit; ++i) 
        if(n % i == 0) return false;
    return true;
}

int main() {
    size_t sz, n, k, count = 0;
    if(scanf("%zu%zu%zu", &sz, &n, &k) != 3) return 0;
    while(!isPrime(sz)) ++sz;

    unsigned val;
    vector<unsigned> table(sz, 0);
    for(size_t i = 0; i < n && scanf("%u", &val); ++i) {
        bool inserted = false;
        for(size_t offset = 0; offset < sz && !inserted; ++offset) {
            size_t idx = (val + offset * offset) % sz;
            if(table[idx] == 0) table[idx] = val, inserted = true;
        }
        if(!inserted) printf("%u cannot be inserted.\n", val);
    }
    for(size_t i = 0, offset; i < k && scanf("%u", &val); ++i) {
        for(offset = 0; offset < sz; ++offset) {
            size_t idx = (val + offset * offset) % sz;
            if(table[idx] == val || table[idx] == 0) break;
        }
        count += offset + 1;
    }
    printf("%.1f\n", (double)count / k);
    return 0;
}