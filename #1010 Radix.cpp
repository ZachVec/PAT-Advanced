#include <iostream>
using namespace std;
typedef unsigned long long BigInt;

BigInt toRadix10(string s, BigInt radix){
    BigInt ans = 0;
    for(const char c : s) {
        ans = ans * radix + (isdigit(c) ? (c - '0') : (c - 'a' + 10));
    }
    return ans;
}

BigInt minValidRadix(string s) {
    char temp = 0;
    for(const char c : s) {
        if(c > temp) temp = c;
    }
    int a = isdigit(temp) ? temp - '0' : temp - 'a' + 10;
    return BigInt(1 + a);
}

BigInt radixIfEqual(string s1, string s2, BigInt radix) {
    BigInt a = toRadix10(s1, radix), b, l, r, mid;
    l = minValidRadix(s2);
    r = l > a ? l : a;
    while(l <= r) {
        mid = (l + r) / 2;
        if(a == (b = toRadix10(s2, mid))) return mid;
        else if(a > b) l = mid + 1;
        else r = mid - 1;
    }
    return BigInt(-1);
}

int main() {
    string a, b;
    BigInt tag, radix, ans;
    cin >> a >> b >> tag >> radix;
    ans = tag == 1 ? radixIfEqual(a, b, radix) : radixIfEqual(b, a, radix);
    if(ans == BigInt(-1)) printf("Impossible\n");
    else printf("%llu\n", ans);
    return 0;
}
/* input
6 110 1 10
2

1 1 1 10
*/