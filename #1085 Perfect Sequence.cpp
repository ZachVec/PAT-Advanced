#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long BigInt;

int main() {
    size_t n, ans = 0; BigInt p;
    if(scanf("%zu%lld", &n, &p) != 2) return 0;

    vector<BigInt> numbers(n);
    for(BigInt &number : numbers) if(!scanf("%lld", &number)) return 0;
    sort(numbers.begin(), numbers.end());
    for(vector<BigInt>::iterator begin = numbers.begin(), end; begin != numbers.end(); ++begin) {
        end = upper_bound(begin, numbers.end(), (*begin) * p);
        ans = max(size_t(end-begin), ans);
    }
    printf("%zu\n", ans);
    return 0;
}