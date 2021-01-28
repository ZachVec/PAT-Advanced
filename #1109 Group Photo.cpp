#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    ssize_t n, k;
    vector<ssize_t> id;
    if(scanf("%zu%zu%*c", &n, &k) != 2) return 0;

    vector<char[9]>  name(n);
    vector<unsigned> height(n);
    for(ssize_t i = 0; i < n && scanf("%s %u%*c", name[i], &height[i]); ++i) {
        id.emplace_back(i);
    }
    
    sort(id.begin(), id.end(), [&height, &name](const ssize_t &a, const ssize_t &b){ 
        return height[a] != height[b] ? height[a] > height[b] : strcmp(name[a], name[b]) < 0; 
    });

    vector<ssize_t> row(n - n / k * (k-1));
    for(ssize_t i = 0, now = 0, rowCnt = n / k; i < k; ++i) {
        ssize_t sz = (i == 0 ? rowCnt + n % rowCnt: rowCnt), r = sz / 2, l = r - 1;
        for(ssize_t j = 0; j < sz; ++j) row[j % 2 == 0 ? r++ : l--] = id[now++];
        for(ssize_t j = 0; j < sz; ++j) printf("%s%c", name[row[j]], " \n"[j == sz - 1]);
    }
    return 0;
}