#include <iostream>
#include <vector>
using namespace std;

int main() {
    bool flag = true;
    unsigned carry = 0;
    vector<unsigned> num, counts(10, 0);
    for(unsigned i; scanf("%1u", &i) != EOF; num.push_back(i)) ++counts[i];
    for(auto it = num.rbegin(); it != num.rend(); ++it) {
        *it = *it * 2 + carry;
        carry = *it / 10;
        *it = *it % 10;
    }
    if(carry != 0) num.insert(num.begin(), carry);
    for(const unsigned i : num) --counts[i];
    for(size_t i = 0; i < counts.size() && flag; ++i)
        flag = flag && (counts[i] == 0);
    printf("%s\n", flag ? "Yes" : "No");
    for(const unsigned i : num) printf("%u", i);
    putchar('\n');
    return 0;
}

/*
1234567899

Yes
2469135798
*/