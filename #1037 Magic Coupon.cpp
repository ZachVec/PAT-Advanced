#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int temp, ans = 0;
    size_t n, m;
    vector<int> coupon, product;
    if(scanf("%zu", &n) != 1) return 0;
    for(size_t i = 0; i < n && scanf("%d", &temp); ++i)
        coupon.emplace_back(temp);
    if(scanf("%zu", &m) != 1) return 0;
    for(size_t i = 0; i < m && scanf("%d", &temp); ++i)
        product.emplace_back(temp);
    
    sort(coupon.begin(), coupon.end());
    sort(product.begin(), product.end());
    for(auto c = coupon.begin(), p = product.begin(); c != coupon.end() && p != product.end(); ++c, ++p) {
        if(*c > 0 || *p > 0) break;
        ans += (*c) * (*p);
    }
    for(auto c = coupon.rbegin(), p = product.rbegin(); c != coupon.rend() && p != product.rend(); ++c, ++p) {
        if(*c < 0 || *p < 0) break;
        ans += (*c) * (*p);
    }
    printf("%d\n", ans);
    return 0;
}