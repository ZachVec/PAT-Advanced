#include <iostream>
#include <vector>
using namespace std;
typedef pair<size_t, double> Term;

int main() {
    size_t exp;
    double coe, *terms = new double[2001]();
    vector<Term> poly[2], ans;
    for(size_t i = 0, n; i < 2 && scanf("%zu", &n); ++i) {
        for(size_t j = 0; j < n; ++j) {
            scanf("%zu%lf", &exp, &coe);
            poly[i].emplace_back(exp, coe);
        }
    }

    for(const Term &t1 : poly[0]) {
        for(const Term &t2 : poly[1]) {
            terms[t1.first + t2.first] += (t1.second * t2.second);
        }
    }

    for(size_t i = 0; i < 2001; ++i) {
        if(terms[i] != 0) ans.emplace_back(i, terms[i]);
    }
    delete[] terms;
    
    printf("%zu", ans.size());
    for(auto it = ans.rbegin(); it != ans.rend(); ++it) {
        printf(" %zu %.1f", it->first, it->second);
    }
    putchar('\n');
    return 0;
}
/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5

3 3 3.6 2 6.0 1 1.6
*/