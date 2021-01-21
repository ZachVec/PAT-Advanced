#include <iostream>
inline int GCD(const int& a, const int &b) { return b == 0 ? a : GCD(b, a % b); }
int main() {
    size_t n;
    if(!scanf("%zu", &n)) return 0;

    auto simplify = [](int &whole, int &numerator, int &denominator) {
        whole += numerator / denominator; numerator %= denominator;
        int gcd = GCD(numerator, denominator);
        numerator /= gcd; denominator /= gcd;
    };

    int w = 0, up1 = 0, down1 = 1; // w - whole
    for(int up2, down2; n-- && scanf("%d/%d", &up2, &down2); simplify(w, up1, down1)) {
        int gcd = GCD(down1, down2);
        int multiplier1 = down2 / gcd;
        int multiplier2 = down1 / gcd;
        up1   =   up1 * multiplier1 + up2 * multiplier2;
        down1 = down1 * multiplier1;
    }
    if(up1 == 0) printf("%d\n", w);
    else if(w == 0) printf("%d/%d\n", up1, down1);
    else printf("%d %d/%d\n", w, up1, down1);
    return 0;
}