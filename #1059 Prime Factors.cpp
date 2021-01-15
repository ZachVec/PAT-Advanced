#include <iostream>
#include <vector>

int main() {
    size_t num;
    if(!scanf("%zu", &num)) return 0;
    std::vector<bool> isPrime(50000, true);
    isPrime[0] = isPrime[1] = false;
    for(size_t i = 2; i < 50000; ++i) {
        if(!isPrime[i]) continue;
        for(size_t j = 2 * i; j < 50000; j *= 2) isPrime[j] = false;
    }

    printf("%zu=", num);
    if(num == 1) putchar('1');
    for(size_t i = 2, n = num, exp; i < 50000 && n != 1; ++i) {
        if(!isPrime[i] || n % i != 0) continue;
        if(n != num) putchar('*');
        for(exp = 0; n % i == 0; ++exp) n /= i;
        printf("%zu", i);
        if(exp != 1) printf("^%zu", exp);
    }
    putchar('\n');
    return 0;
}