#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
void lookAndSay(char *str, char *ans, const size_t &n){
    if(n == 1) strcpy(ans, str);
    else {
        size_t len = 0, cnt = 0;
        for(char *anchor = str; *anchor != 0; anchor += cnt, cnt = 0) {
            for(char *p = anchor; *p == *anchor; ++p, ++cnt);
            ans[len++] = *anchor;
            ans[len++] = cnt + '0';
        }
        ans[len] = 0;
        lookAndSay(ans, str, n-1);
    }
}

int main() {
    size_t n;
    char str[100000], ans[100000];

    if(scanf("%s%zu", str, &n) != 2) return 0;
    lookAndSay(str, ans, n);
    printf("%s\n", ans);
    return 0;
}