#include <iostream>
#include <vector>
using namespace std;
vector<int> ori, post;
typedef bool (*CMP)(const int &a, const int &b);
inline bool lt(const int &a, const int &b) { return a <  b; }  // less than
inline bool ge(const int &a, const int &b) { return a >= b; }  // greater or equal to

void getPost(size_t l, size_t r, const CMP &cmp) {
    if(l == r) return;
    size_t i, j;
    for(i = l + 1; i < r && cmp(ori[i], ori[l]); ++i);
    for(j = i; j < r && !cmp(ori[j], ori[l]); ++j);
    getPost(l + 1, i, cmp);
    getPost(i, j, cmp);
    post.emplace_back(ori[l]);
}

int main() {
    size_t n;
    if(scanf("%zu", &n) != 1) return 0;
    ori.resize(n);
    for(int &val : ori) if(!scanf("%d", &val)) return 0;
    if(n == 1) getPost(0, ori.size(), lt);
    else getPost(0, ori.size(), lt(ori[1], ori[0]) ? lt : ge);
    if(ori.size() == post.size()) {
        printf("YES\n");
        for(size_t i = 0; i < n; ++i) 
            printf("%d%c", post[i], " \n"[i == n - 1]);
    }
    else printf("NO\n");
    return 0;
}