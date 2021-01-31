#include <iostream>
#include <vector>
using namespace std;

int main() {
    size_t k; char str[1001];

    if(scanf("%zu%s", &k, str) != 2) return 0;
    pair<char, unsigned> cnt{'\0', 0};
    vector<bool> isStuck(256, true), isPrinted(256, false);
    for(char *p = str; ; ++p) {
        if(*p != cnt.first) {
            isStuck[cnt.first] = isStuck[cnt.first] && cnt.second % k == 0;
            cnt = {*p, 1};
        }
        else ++cnt.second;
        if(*p == '\0') break;
    }
    
    for(char *p = str; *p != '\0'; ++p) {
        if(!isStuck[*p] || isPrinted[*p]) continue;
        putchar(*p); isPrinted[*p] = true;
    }

    putchar('\n');
    for(char *p = str; *p != '\0'; p += (isStuck[*p] ? k : 1)) putchar(*p);
    putchar('\n');
    return 0;
}