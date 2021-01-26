#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, ssize_t, ssize_t> Node;
typedef priority_queue<int, vector<int>, greater<int>> Queue; 

void inorder(vector<Node> &nodes, Queue &q, const ssize_t &root){
    if(root == -1) return;
    inorder(nodes, q, get<1>(nodes[root]));
    get<0>(nodes[root]) = q.top(); q.pop();
    inorder(nodes, q, get<2>(nodes[root]));
}

int main() {
    ssize_t n;
    if(!scanf("%zd", &n)) return 0;
    vector<Node> nodes;
    for(ssize_t i = 0, l, r; i < n && scanf("%zd%zd", &l, &r); ++i) {
        nodes.emplace_back(0, l, r);
    }
    Queue q; int temp;
    for(ssize_t i = 0; i < n && scanf("%d", &temp); ++i) q.emplace(temp);
    
    inorder(nodes, q, 0);
    queue<ssize_t> levelOrder; temp = 0;
    for(levelOrder.push(0); !levelOrder.empty(); levelOrder.pop()) {
        if(levelOrder.front() == -1) continue;
        printf("%d%c", get<0>(nodes[levelOrder.front()]), " \n"[++temp == n]);
        levelOrder.emplace(get<1>(nodes[levelOrder.front()]));
        levelOrder.emplace(get<2>(nodes[levelOrder.front()]));
    }
    return 0;
}