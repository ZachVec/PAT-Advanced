#include <iostream>

int main() {
    const char *mappings = "0123456789ABC";
    putchar('#');
    for(size_t i = 0, n; i < 3 && scanf("%zu", &n); ++i) 
        printf("%c%c", mappings[n / 13], mappings[n % 13]);
    putchar('\n');
    return 0;
}