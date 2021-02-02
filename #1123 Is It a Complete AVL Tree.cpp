#include <iostream>
#include <queue>
using namespace std;
typedef struct Node{
    int val, height;
    Node *lchild, *rchild;
    Node(int _val) : val(_val), height(1), lchild(NULL), rchild(NULL) {}
} *pNode;

inline int height(const pNode &node) { return node == NULL ? 0 : node->height; }
inline int balFac(const pNode &node) { return height(node->lchild) - height(node->rchild); }
inline void updateHeight(const pNode &node) { node->height = 1 + max(height(node->lchild), height(node->rchild)); }
pNode lRotate(const pNode &node) {
    pNode newRoot = node->rchild;
    node->rchild = newRoot->lchild;
    newRoot->lchild = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}
pNode rRotate(const pNode &node) {
    pNode newRoot = node->lchild;
    node->lchild = newRoot->rchild;
    newRoot->rchild = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}
pNode rebalance(const pNode &node, const int &bf){ 
    if(bf == 2) {
        if(balFac(node->lchild) == 1) return rRotate(node);
        else {
            node->lchild = lRotate(node->lchild);
            return rRotate(node);
        }
    }
    else if(bf == -2){
        if(balFac(node->rchild) == -1) return lRotate(node);
        else {
            node->rchild = rRotate(node->rchild);
            return lRotate(node);
        }
    }
    return node;
}
pNode insert(const pNode &node, const int &val) {
    if(node == NULL) return new Node(val);
    else if(val <= node->val) node->lchild = insert(node->lchild, val);
    else node->rchild = insert(node->rchild, val);
    updateHeight(node);
    return rebalance(node, balFac(node));
}

int main() {
    size_t n;
    pNode root = NULL;
    if(!scanf("%zu", &n)) return 0;
    for(int val; n-- && scanf("%d", &val); root = insert(root, val));

    queue<pNode> q;
    bool nullShowUp = false, isComplete = true;
    for(q.emplace(root); !q.empty(); q.pop()) {
        if(q.front()->lchild != NULL) {
            q.emplace(q.front()->lchild);
            if(nullShowUp) isComplete = false;
        }
        else nullShowUp = true;
        if(q.front()->rchild != NULL) {
            q.emplace(q.front()->rchild);
            if(nullShowUp) isComplete = false;
        }
        else nullShowUp = true;
        printf("%d%c", q.front()->val, " \n"[q.size() == 1]);
    }
    printf("%s\n", isComplete ? "YES" : "NO");
    return 0;
}