#include <iostream>
#include <queue>
using namespace std;

typedef struct Node{
    Node *l, *r;
    int val;
    Node(const int &_val) : l(NULL), r(NULL), val(_val){}
} *pNode;

void insert(pNode &node, const int &val) {
    if(node == NULL) node = new Node(val);
    else if(val <= node->val) insert(node->l, val);
    else insert(node->r, val);
}

int main() {
    size_t n;
    if(!scanf("%zu", &n)) return 0;

    pNode root = NULL;
    for(int number; n-- && scanf("%d", &number); )
        insert(root, number);

    pair<size_t, size_t> ans{1, 0};
    queue<pNode> q;
    for(q.push(root); !q.empty(); ans = {q.size(), ans.first}) {
        for(size_t sz = q.size(); sz--; q.pop()) {
            if(q.front()->l != NULL) q.emplace(q.front()->l);
            if(q.front()->r != NULL) q.emplace(q.front()->r);
        }
        if(q.empty()) printf("%zu + %zu = %zu\n", ans.first, ans.second, ans.first + ans.second);
    }
    return 0;
}