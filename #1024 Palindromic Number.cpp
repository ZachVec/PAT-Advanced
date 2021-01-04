#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    unsigned s = 0, step;
    vector<unsigned> ori, rev;
    for(char temp = getchar(); temp != ' '; temp = getchar()) ori.push_back(temp - '0');
    scanf("%u", &step);
    for(unsigned carry, temp; s < step; ++s) {
        rev = ori; carry = 0;
        reverse(rev.begin(), rev.end());
        if(rev == ori) break;
        for(size_t i = 0; i < ori.size(); ++i) {
            temp = ori[i] + rev[i] + carry;
            ori[i] = temp % 10;
            carry = temp / 10;
        }
        if(carry != 0) ori.push_back(carry);
    }
    for(auto it = ori.rbegin(); it != ori.rend(); ++it) printf("%u", *it);
    printf("\n%u\n", s);
    return 0;
}

/*
67 3
484
2

69 3
s = 0
ori: 6 9, rev: 9 6
ori: 5 6 1
output: 165

s = 1
ori: 5 6 1, rev: 1 6 5
ori: 6 2 7
output

s = 2
ori: 6 2 7, rev: 7 2 6
ori: 3 5 3 1

1353
3
*/