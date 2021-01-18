#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    auto toDigits = [](unsigned num, vector<unsigned> &digits) {
        digits.clear();
        for(size_t i = 0; i < 4; ++i, num /= 10) digits.emplace_back(num % 10);
    };
    auto toNumber = [](unsigned &num, vector<unsigned> number) {
        num = 0;
        for(const unsigned i : number) num = num * 10 + i;
    };

    unsigned num, a = 0, b = 0;
    if(!scanf("%u", &num)) return 0;

    vector<unsigned> digits, inc, dec;
    do{
        toDigits(num, digits); inc = dec = digits; 
        sort(inc.begin(), inc.end(), less<unsigned>());
        sort(dec.begin(), dec.end(), greater<unsigned>());
        toNumber(a, dec); toNumber(b, inc);
        printf("%04u - %04u = %04u\n", a, b, num = a - b);
    }
    while(num != 0 && num != 6174);
    return 0;
}