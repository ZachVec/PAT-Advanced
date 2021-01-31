#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    size_t n; 
    if(!scanf("%zu", &n)) return 0;
    vector<unsigned> numbers(n+1, 0);
    for(unsigned &i : numbers) if(!scanf("%u", &i)) return 0;
    sort(numbers.begin(), numbers.end());
    for(auto it = numbers.begin() + 1; it != numbers.end(); ++it) *it += *(it-1);
    printf("%zu %u\n", n % 2, numbers[n] - 2 * numbers[n/2]);
    return 0;
}