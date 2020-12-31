#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int main() {
    vector<pair<size_t, double>> ans;
    double temp[1001];
    memset(temp, 0, sizeof(temp));
    for(size_t i = 0, k, exp; i < 2 && scanf("%zu", &k); ++i) {
        double coe;
        for(size_t j = 0; j < k; ++j) {
            scanf("%zu%lf", &exp, &coe);
            temp[exp] += coe;
        }
    }
    for(size_t i = 0; i < 1001; ++i) {
        if(temp[i] != 0) ans.emplace_back(i, temp[i]);
    }
    printf("%zu", ans.size());
    for(auto it = ans.rbegin(); it != ans.rend(); it++) {
        printf(" %zu %.1f", it->first, it->second);
    }
    putchar('\n');
    return 0;
}


/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5

3 2 1.5 1 2.9 0 3.2
*/