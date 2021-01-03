#include <iostream>
#include <vector>
using namespace std;
vector<unsigned> toRadix(unsigned n, unsigned radix) {
    vector<unsigned> ans;
    do{
        ans.emplace_back(n % radix);
        n /= radix;
    }
    while(n != 0);
    return ans;
}

int main() {
    unsigned n, radix;
    if(scanf("%u%u", &n, &radix) == EOF) return 0;
    vector<unsigned> res = toRadix(n, radix);
    size_t i, bound = res.size()/2;
    for(i = 0; i < bound; ++i) {
        if(res[i] != res[res.size()-1-i]) break;
    }
    printf("%s\n", i == bound ? "Yes":"No");
    for(i = res.size()-1; i != 0; --i) {
        printf("%u ", res[i]);
    }
    printf("%u\n", res[0]);
}

/*
27 2

Yes
1 1 0 1 1


121 5

No
4 4 1
*/