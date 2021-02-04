#include <iostream>
#include <vector>
using namespace std;
const size_t notExist = -1;
typedef pair<size_t, size_t> Child;
void infix(const vector<char[11]> &data, const vector<Child> &children, const size_t &root){
    if(root == notExist) return;
    else if(children[root].first == notExist && children[root].second == notExist) printf("%s", data[root]);
    else {
        putchar('(');
        infix(data, children, children[root].first);
        printf("%s", data[root]);
        infix(data, children, children[root].second);
        putchar(')');
    }
}

int main() {
    size_t n, root;
    if(!scanf("%zu", &n)) return 0;

    vector<bool> notRoot(n+1);
    vector<char[11]> str(n+1);
    vector<Child> children(n+1);
    for(size_t i = 1; i <= n && scanf("%s%zu%zu\n", str[i], &children[i].first, &children[i].second); ++i) {
        if(children[i].first !=  notExist) notRoot[children[i].first]  = true;
        if(children[i].second != notExist) notRoot[children[i].second] = true;
    }
    for(root = 1; notRoot[root]; ++root);
    infix(str, children, children[root].first);
    printf("%s", str[root]);
    infix(str, children, children[root].second);
    putchar('\n');
    return 0;
}