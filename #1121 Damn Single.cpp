#include <iostream>
#include <vector>
using namespace std;
constexpr size_t notExist = -1;

int main() {
    size_t n, k, cnt;
    if(!scanf("%zu", &n)) return 0;

    vector<bool> isSingle(100000, false);
    vector<size_t> coupleOf(100000, notExist);
    for(size_t i = 0, u, v; i < n && scanf("%zu%zu", &u, &v); ++i) {
        coupleOf[u] = v; coupleOf[v] = u;
    }

    if(!scanf("%zu", &k)) return 0;
    cnt = k;
    for(size_t i = 0, guest; i < k && scanf("%zu", &guest); ++i) {
        if(coupleOf[guest] != notExist && isSingle[coupleOf[guest]]) {
            isSingle[coupleOf[guest]] = false; cnt -= 2;
        }
        else isSingle[guest] = true;
    }
    
    printf("%zu\n", cnt);
    for(size_t guest = 0; guest < isSingle.size() && cnt != 0; ++guest) {
        if(!isSingle[guest]) continue;
        printf("%05zu%c", guest, " \n"[--cnt == 0]);
    }
    return 0;
}