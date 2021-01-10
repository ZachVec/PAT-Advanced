#include <iostream>
const char *str = "SHCDJ";

int main() {
    size_t n;
    unsigned temp, cards[54], idx[54], aux[54];
    if(scanf("%zu", &n) != 1) return 0;
    for(size_t i = 0; i < 54 && scanf("%u", &temp); ++i){
        cards[i] = i;
        idx[i] = temp - 1;
    }
    for(size_t i = 0; i < n; ++i) {
        for(size_t j = 0; j < 54; ++j) aux[j] = cards[j];
        for(size_t j = 0; j < 54; ++j) cards[idx[j]] = aux[j];
    }
    for(size_t i = 0; i < 54; ++i) 
        printf("%c%u%c", str[cards[i] / 13], 1 + cards[i] % 13, " \n"[i == 53]);
    return 0;
}