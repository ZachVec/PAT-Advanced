#include<iostream>
int main() {
    size_t n, ans = 0;
    if(!scanf("%zu", &n)) return 0;
    
    double temp = 0;
    for(size_t i = 1; i <= n && scanf("%lf", &temp); ++i) {
        ans += size_t(1000 * temp) * i * (n - i + 1); 
    }
    printf("%.2f\n", double(ans) / 1000);
    return 0;
}