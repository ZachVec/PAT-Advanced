#include <iostream>

int main() {
    unsigned n, ans = 0;
    if(!scanf("%u", &n)) return 0;
    for(unsigned div = 1; n / div != 0; div *= 10) {
        unsigned r = n % div, d = n / div % 10, l = n / div / 10;
        if(d < 1) ans += l * div;
        else if(d == 1) ans += l * div + r + 1;
        else ans += (l + 1) * div;
    }
    printf("%u\n", ans);
    return 0;
}