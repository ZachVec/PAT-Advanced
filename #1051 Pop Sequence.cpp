#include <iostream>
#include <stack>
using namespace std;

int main() {
    size_t m, n, k; // m - cap, n - length of sequence, k - #sequence
    if(scanf("%zu%zu%zu", &m, &n, &k) != 3) return 0;
    for(size_t i = 0; i < k; ++i) {
        bool isPopSeq = true;
        unsigned num, now = 1;
        stack<unsigned> s;
        for(size_t j = 0; j < n && scanf("%u", &num); ++j) {
            if(!isPopSeq) continue;
            while(s.empty() || s.top() < num) s.emplace(now++);
            if(!s.empty() && s.size() <= m && s.top() == num) s.pop();
            else isPopSeq = false;
        }
        printf("%s\n", isPopSeq ? "YES" : "NO");
    }
    return 0;
}