#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<unsigned> BFS(vector<size_t> *tree, size_t src){
    unsigned cnt = 0;
    queue<size_t> q;
    vector<unsigned> ans;
    for(q.push(src); !q.empty(); cnt = 0) {
        for(size_t i = q.size(); i-- > 0; q.pop()) {
            if(tree[q.front()].empty()) ++cnt;
            for(size_t child: tree[q.front()]) q.push(child);
        }
        ans.push_back(cnt);
    }
    return ans;
}

int main() {
    size_t n, m;
    if(scanf("%zu%zu", &n, &m) == EOF || n == 0) return 0;
    vector<size_t> *tree = new vector<size_t>[n+1]();
    for(size_t i = 0, id, k; i < m; ++i) {
        scanf("%zu%zu", &id, &k);
        for(size_t j = 0, cid; j < k; ++j) {
            scanf("%zu", &cid);
            tree[id].emplace_back(cid);
        }
    }
    vector<unsigned> ans = BFS(tree, 1);
    for(size_t i = 0; i < ans.size();) {
        printf("%u", ans[i++]);
        printf("%c", " \n"[i==ans.size()]);
    }
    return 0;
}
/* input
2 1
01 1 02
*/
/* output
0 1
*/