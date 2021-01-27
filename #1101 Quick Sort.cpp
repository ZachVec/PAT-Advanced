#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    size_t n;
    if(!scanf("%zu", &n)) return 0;

    vector<unsigned> ori(n), srt, ans;
    for(size_t i = 0; i < n && scanf("%u", &ori[i]); ++i);
    srt = ori; sort(srt.begin(), srt.end());

    unsigned maximum = 0;
    for(size_t i = 0; i < ori.size(); ++i) {
        if(ori[i] == srt[i] && ori[i] > maximum) ans.emplace_back(ori[i]);
        maximum = max(ori[i], maximum);
    }
    printf("%zu\n", ans.size());
    for(size_t i = 0; i < ans.size(); ++i) {
        if(i != 0) putchar(' ');
        printf("%u", ans[i]);
    }
    putchar('\n');
    return 0;
}