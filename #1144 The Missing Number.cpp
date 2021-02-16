#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t n, idx;
    if(!scanf("%zu", &n)) return 0;

    vector<bool> showedUp(100001, false);
    for(size_t i = 0, val; i < n && scanf("%zu", &val); ++i) {
        if(0 < *reinterpret_cast<ssize_t *>(&val) && val < showedUp.size()) showedUp[val] = true;
    }
    for(idx = 1; idx < showedUp.size() && showedUp[idx]; ++idx);

    printf("%zu\n", idx);
    return 0;
}