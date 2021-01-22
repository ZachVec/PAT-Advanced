#include <iostream>
#include <utility>
typedef long long BigInt;
typedef std::pair<BigInt, BigInt> Fraction;
BigInt GCD(const BigInt &a, const BigInt &b) {return b == 0 ? a : GCD(b, a % b); } 

Fraction simplify(Fraction frac) {
    if(frac.second < 0) frac.first = -frac.first, frac.second = -frac.second;
    int gcd = GCD(std::abs(frac.first), frac.second);
    frac.first /= gcd; frac.second /= gcd;
    return frac;
}

void print(Fraction frac){
    if(frac.second == 0) printf("Inf");
    else if(frac.first == 0 || frac.second == 1) printf(frac.first < 0 ? "(%lld)" : "%lld", frac.first);
    else if(std::abs(frac.first) < frac.second) printf(frac.first < 0 ? "(%lld/%lld)" : "%lld/%lld", frac.first, frac.second);
    else printf(frac.first < 0 ? "(%lld %lld/%lld)" : "%lld %lld/%lld", frac.first / frac.second, std::abs(frac.first) % frac.second, frac.second);
}

int main() {
    Fraction a, b, c;
    if(scanf("%lld/%lld %lld/%lld", &a.first, &a.second, &b.first, &b.second) != 4) return 0;
    a = simplify(a); b = simplify(b); 
    c = {a.first * b.second + a.second * b.first, a.second * b.second};
    print(a); printf(" + "); print(b); printf(" = "); print(simplify(c)); putchar('\n');
    c = {a.first * b.second - a.second * b.first, a.second * b.second};
    print(a); printf(" - "); print(b); printf(" = "); print(simplify(c)); putchar('\n');
    c = {a.first * b.first, a.second * b.second};
    print(a); printf(" * "); print(b); printf(" = "); print(simplify(c)); putchar('\n');
    c = {a.first * b.second, a.second * b.first};
    print(a); printf(" / "); print(b); printf(" = "); print(simplify(c)); putchar('\n');
    return 0;
}