#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

auto inputTree(const vector<int> &pre, const vector<int> &pst, unordered_map<int, size_t> &index, vector<int> &ans) {
    auto wrapped = [&pre, &pst, &index, &ans](const size_t &preLo, const size_t &pstLo, const size_t &len, const auto &wrapped_ref) -> bool {
        if(len == 0) return false;
        else if(len == 1) {
            ans.emplace_back(pre[preLo]);
            return true;
        }
        else {
            size_t leftLen  = index[pre[preLo + 1]] + 1 - pstLo;
            size_t rightLen = len - 1 - leftLen;
            bool flag1 = wrapped_ref(preLo + 1, pstLo, leftLen, wrapped_ref);
            ans.emplace_back(pre[preLo]);
            bool flag2 = wrapped_ref(preLo + 1 + leftLen, pstLo + leftLen, rightLen, wrapped_ref);
            return flag1 && flag2;
        }
    };
    return wrapped;
}

int main() {
    size_t n;
    if(!scanf("%zu", &n)) return 0;
    
    vector<int> pre(n), pst(n), ans;
    unordered_map<int, size_t> idx;
    for(size_t i = 0; i < n && scanf("%d", &pre[i]); ++i);
    for(size_t i = 0; i < n && scanf("%d", &pst[i]); ++i) idx[pst[i]] = i;
    auto buildTree = inputTree(pre, pst, idx, ans);
    printf("%s\n", buildTree(0, 0, n, buildTree) ? "Yes" : "No");
    for(size_t i = 0; i < ans.size(); ++i) {
        printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
    }
    return 0;
}