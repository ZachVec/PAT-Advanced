#include <iostream>
typedef struct Node{
    int val, height, balFac;
    Node *lchild, *rchild;
    Node(int v) : val(v), height(0), balFac(0),lchild(NULL), rchild(NULL){}
} *pNode;

inline int height(pNode node) { return node ? node->height : -1; }
inline int balFac(pNode node) { return node ? node->balFac : 0; }

void update(pNode node) { 
    node->height = 1 + std::max(height(node->lchild), height(node->rchild));
    node->balFac = height(node->lchild) - height(node->rchild);
}

pNode lRotate(pNode root) {
    pNode newRoot   = root->rchild;
    root->rchild    = newRoot->lchild;
    newRoot->lchild = root;
    update(root);
    update(newRoot);
    return newRoot;
}

pNode rRotate(pNode root) {
    pNode newRoot   = root->lchild;
    root->lchild    = newRoot->rchild;
    newRoot->rchild = root;
    update(root);
    update(newRoot);
    return newRoot;
}

pNode rebalance(pNode node) {
    if(balFac(node) == 2) {  // left heavy
        if(balFac(node->lchild) == 1) return rRotate(node);
        else {
            node->lchild = lRotate(node->lchild);
            return rRotate(node);
        }
    }
    else if(balFac(node) == -2){
        if(balFac(node->rchild) == -1) return lRotate(node);
        else {
            node->rchild = rRotate(node->rchild);
            return lRotate(node);
        }
    }
    return node;
}

pNode insert(pNode node, int val) {
    if(!node) return new Node(val);
    else if(val < node->val) node->lchild = insert(node->lchild, val);
    else node->rchild = insert(node->rchild, val);
    update(node);
    return rebalance(node);
}

int main() {
    size_t n;
    int val;
    pNode root = NULL;
    if(!scanf("%zu", &n)) return 0;
    for(size_t i = 0; i < n && scanf("%d", &val); ++i) root = insert(root, val);
    printf("%d\n", root->val);
    return 0;
}