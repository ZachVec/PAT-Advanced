#include <iostream>
#include <vector>
using namespace std;
constexpr size_t MAXN = 10008;

void findPrime(vector<bool> &prime) {
    for(size_t i = 2; i < prime.size(); ++i) {
        if(!prime[i]) continue;
        for(size_t j = 2 * i; j < prime.size(); j += i) 
            prime[j] = false;
    }
}

int main() {
    vector<bool> prime(MAXN, true);
    prime[0] = prime[1] = false; findPrime(prime);

    size_t sz, n;
    if(scanf("%zu%zu", &sz, &n) != 2) return 0;
    while(!prime[sz]) ++sz;

    vector<bool> isOccupied(sz, false);
    for(size_t i = 1, num, pos, j; i <= n && scanf("%zu", &num); ++i) {
        // when j >= sz, then j = sz + k, so (num + j * j) % sz equals to (num + k * k) % sz
        // so the upper limit of j should be sz
        for(j = 1, pos = num % sz; j < sz && isOccupied[pos]; ++j) pos = (num + j * j) % sz;
        isOccupied[pos] = true;
        if(j == sz) putchar('-');
        else printf("%zu", pos);
        putchar(" \n"[i == n]);
    }
    return 0;
}