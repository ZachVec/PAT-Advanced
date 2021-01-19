#include <iostream>
#include <vector>
using namespace std;

int main() {
    int exp;
    vector<char> base;

    if(getchar() == '-') putchar('-');
    for(char ch = getchar(); ch != 'E'; ch = getchar()) base.emplace_back(ch);
    if(!scanf("%d", &exp)) return 0;
    base.erase(base.begin() + 1);

    if(exp < 0) {
        printf("0."); while(++exp) putchar('0');  // output leading zeros
        for(const char ch : base) putchar(ch);
    }
    else {
        for(size_t i = 0, dotPos = exp + 1; i < dotPos || i < base.size(); ++i) {
            if(i == dotPos) putchar('.');
            putchar(i < base.size() ? base[i] : '0');
        }
    }
    putchar('\n');
    return 0;
}