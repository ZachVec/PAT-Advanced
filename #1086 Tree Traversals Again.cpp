#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef size_t Vertex;

void genPost(const vector<Vertex> &pre, const vector<Vertex> &in, vector<Vertex> &post, size_t preL, size_t inL, size_t len){
    if(len == 0) return;
    size_t rootIdx = inL;
    while(rootIdx < inL + len && in[rootIdx] != pre[preL]) ++rootIdx;
    genPost(pre, in, post, preL + 1, inL, rootIdx - inL); // left
    genPost(pre, in, post, preL + 1 + rootIdx - inL, rootIdx + 1, len - rootIdx + inL - 1); // right
    post.emplace_back(pre[preL]);
}


int main() {
    size_t n, idx;
    if(!scanf("%zu", &n)) return 0;
    
    string cmd;
    stack<Vertex> stk;
    vector<Vertex> in, pre, post;
    for(size_t i = 0; i < 2 * n && cin >> cmd; ++i) {
        if(cmd == "Push" && scanf("%zu", &idx)) {
            pre.emplace_back(idx);
            stk.push(idx);
        }
        else {
            in.emplace_back(stk.top());
            stk.pop();
        }
    }

    genPost(pre, in, post, 0, 0, pre.size());
    for(size_t i = 0; i < post.size(); ++i) {
        printf("%zu%c", post[i], " \n"[i == post.size() - 1]);
    }
    return 0;
}