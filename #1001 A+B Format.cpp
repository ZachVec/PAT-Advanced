#include <iostream>

int main() {
    int a, b, sum, ans[10];
    size_t sz = 0;
    if(!scanf("%d%d", &a, &b)) return 0;
    if((sum = a + b) < 0) {
        putchar('-');
        sum = -sum;
    }
    do {
        ans[++sz] = sum % 10;
        sum /= 10;
    }
    while(sum != 0);
    for(size_t i = sz; i != 0; i--) {
        if(i % 3 == 0 && i != sz) putchar(',');
        printf("%d", ans[i]);
    }
    putchar('\n');
    return 0;
}