#include <iostream>
#include <queue>
#include <unordered_map>
#include <functional>
using namespace std;
using namespace placeholders;
constexpr size_t notExist = -1;
typedef pair<size_t, size_t> Child;

size_t genTree(const vector<int> &inorder, const vector<int> &postOrder, unordered_map<int, size_t> &index, vector<Child> &children){
    auto wrapped = [&inorder, &postOrder, &index, &children](const size_t &inLo, const size_t &postLo, const size_t &len, const auto &wrapped_ref) -> size_t{
        if(len == 0) return -1;
        size_t rootIdx = index[postOrder[postLo + len - 1]];
        size_t leftLen = rootIdx - inLo;
        size_t rightLen = len - leftLen - 1;
        children[rootIdx].first  = wrapped_ref(inLo, postLo, leftLen, wrapped_ref);
        children[rootIdx].second = wrapped_ref(rootIdx + 1, postLo + leftLen, rightLen, wrapped_ref);
        return rootIdx;
    };
    return wrapped(0, 0, inorder.size(), wrapped);
}

int main() {
    size_t n;
    if(!scanf("%zu", &n)) return 0;

    unordered_map<int, size_t> index;
    vector<int> inorder(n), postOrder(n);
    vector<Child> children(n, {notExist, notExist});
    for(size_t i = 0; i < n && scanf("%d", &inorder[i]); ++i) index[inorder[i]] = i;
    for(size_t i = 0; i < n && scanf("%d", &postOrder[i]); ++i);

    vector<size_t> now, nxt, ans;
    now.emplace_back(genTree(inorder, postOrder, index, children));
    for(bool reverse = true; !now.empty(); reverse = !reverse) {
        for(const size_t &idx : now) {
            if(children[idx].first  != notExist) nxt.emplace_back(children[idx].first);
            if(children[idx].second != notExist) nxt.emplace_back(children[idx].second);
        }
        if(reverse) for(const size_t &idx : now) ans.emplace_back(idx);
        else for(auto it = now.rbegin(); it != now.rend(); ++it) ans.emplace_back(*it);
        now = nxt; nxt.clear();
    }
    for(size_t i = 0; i < ans.size(); ++i) {
        printf("%d%c", inorder[ans[i]], " \n"[i == ans.size() - 1]);
    }
    return 0;
}