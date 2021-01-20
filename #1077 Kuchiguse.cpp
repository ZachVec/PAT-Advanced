#include <iostream>
#include <cstring>
using namespace std;
constexpr size_t MAX = 258;

int main() {
    size_t n, orilen, len;
    char str[MAX], suffix[MAX];

    if(!scanf("%zu\n", &n)) return 0;
    cin.getline(suffix, MAX); orilen = len = strlen(suffix);
    
    for(size_t i = 1, slen, j; i < n; ++i, len = j) {
        cin.getline(str, MAX); slen = strlen(str);
        for(j = 0; j < len && j < slen; ++j) {
            if(suffix[orilen - j - 1] != str[slen - j - 1]) break;
        }
    }

    if(len) printf("%s\n", suffix + orilen - len);
    else printf("nai\n");
    return 0;
}