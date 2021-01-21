#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef char string_t[11];
typedef unsigned Grade;

int main(){
    size_t n; 
    if(!scanf("%zu", &n)) return 0;

    vector<size_t>     indices;
    vector<Grade>      grades(n);
    vector<string_t>   names(n), ids(n);
    for(size_t i = 0; i < n && scanf("%s%s%u", names[i], ids[i], &grades[i]); ++i) indices.emplace_back(i);
    sort(indices.begin(), indices.end(), [&grades](const size_t &a, const size_t &b){ return grades[a] > grades[b]; });

    Grade lo, hi;
    if(scanf("%u%u", &lo, &hi) != 2) return 0;

    auto it = lower_bound(indices.begin(), indices.end(), hi, [&grades](const size_t &idx, const Grade &val){ 
        return grades[idx] > val; 
    });
    if(it == indices.end() || grades[*it] < lo) printf("NONE\n");
    for(; it != indices.end() && grades[*it] >= lo; ++it) printf("%s %s\n", names[*it], ids[*it]);
    return 0;
}